#!/usr/bin/env python3
"""
stl_to_rt.py - Convert 3D STL models (ASCII and Binary) into miniRT .rt scene files.

Features:
- Supports both Binary and ASCII STL files.
- Automatically limits the mesh to at most 10,000 triangles (never more).
- If the original model has <= 10,000 triangles, keeps all triangles intact (100% detail).
- If the original model has > 10,000 triangles, simplifies it to <= 10,000 while preserving shape.
- Automatically places the 3D model properly grounded on the floor (Y = 0).
- Centers the model in X and Z axes.
- Automatically generates an optimal ground plane (pl).
- Automatically calculates an ideal camera position and normalized direction vector (C).
- Generates balanced ambient (A) and key lighting (L).
- Concise, clean number formatting for minimal file size.
"""

import sys
import os
import math
import struct
import argparse

DEFAULT_MAX_TRIANGLES = 10000


def parse_stl(filepath):
    """
    Parses an STL file (detects whether it's binary or ASCII).
    Returns a list of triangles: [((x1, y1, z1), (x2, y2, z2), (x3, y3, z3)), ...]
    """
    if not os.path.isfile(filepath):
        raise FileNotFoundError(f"File not found: {filepath}")

    with open(filepath, "rb") as f:
        header = f.read(84)
        file_size = os.path.getsize(filepath)

        # Check if binary STL:
        if len(header) >= 84:
            num_triangles = struct.unpack("<I", header[80:84])[0]
            expected_size = 84 + num_triangles * 50
            if file_size == expected_size:
                return parse_binary_stl(f, num_triangles)

        # Check if ASCII STL:
        f.seek(0)
        start_chunk = f.read(1024)
        if b"\0" not in start_chunk and b"solid" in start_chunk.lower():
            try:
                f.seek(0)
                text = f.read().decode("utf-8", errors="ignore")
                return parse_ascii_stl(text)
            except Exception:
                pass

        # Fallback binary
        if len(header) >= 84:
            f.seek(84)
            num_triangles = struct.unpack("<I", header[80:84])[0]
            return parse_binary_stl(f, num_triangles)

    raise ValueError(f"Unable to parse STL file: {filepath}")


def parse_binary_stl(f, num_triangles):
    """Parses binary STL from byte 84 onward."""
    triangles = []
    data = f.read()
    record_format = "<12fH"
    record_size = struct.calcsize(record_format)

    total_records = len(data) // record_size
    actual_count = min(num_triangles, total_records)

    for i in range(actual_count):
        offset = i * record_size
        fields = struct.unpack_from(record_format, data, offset)
        v1 = (float(fields[3]), float(fields[4]), float(fields[5]))
        v2 = (float(fields[6]), float(fields[7]), float(fields[8]))
        v3 = (float(fields[9]), float(fields[10]), float(fields[11]))
        triangles.append((v1, v2, v3))

    return triangles


def parse_ascii_stl(text):
    """Parses ASCII STL text content."""
    triangles = []
    lines = text.splitlines()
    current_triangle = []

    for line in lines:
        line = line.strip()
        if not line:
            continue
        parts = line.split()
        if len(parts) >= 4 and parts[0].lower() == "vertex":
            x, y, z = float(parts[1]), float(parts[2]), float(parts[3])
            current_triangle.append((x, y, z))
            if len(current_triangle) == 3:
                triangles.append(tuple(current_triangle))
                current_triangle = []

    return triangles


def rotate_point(pt, rx, ry, rz):
    """Rotates a point by rx, ry, rz in degrees."""
    x, y, z = pt

    if rx != 0:
        rad = math.radians(rx)
        c, s = math.cos(rad), math.sin(rad)
        y, z = y * c - z * s, y * s + z * c

    if ry != 0:
        rad = math.radians(ry)
        c, s = math.cos(rad), math.sin(rad)
        x, z = x * c + z * s, -x * s + z * c

    if rz != 0:
        rad = math.radians(rz)
        c, s = math.cos(rad), math.sin(rad)
        x, y = x * c - y * s, x * s + y * c

    return (x, y, z)


def normalize_vector(v):
    """Normalizes a 3D vector."""
    x, y, z = v
    length = math.sqrt(x * x + y * y + z * z)
    if length < 1e-12:
        return (0.0, 1.0, 0.0)
    return (x / length, y / length, z / length)


def simplify_mesh(triangles, max_limit=DEFAULT_MAX_TRIANGLES):
    """
    Ensures mesh does not exceed max_limit triangles (10,000 max).
    If len(triangles) <= max_limit, returns original list unchanged.
    If len(triangles) > max_limit, reduces using grid clustering and subsampling.
    Guaranteed: len(result) <= max_limit.
    """
    if len(triangles) <= max_limit:
        return triangles

    min_x = min_y = min_z = float("inf")
    max_x = max_y = max_z = float("-inf")
    for v1, v2, v3 in triangles:
        for x, y, z in (v1, v2, v3):
            if x < min_x: min_x = x
            if x > max_x: max_x = x
            if y < min_y: min_y = y
            if y > max_y: max_y = y
            if z < min_z: min_z = z
            if z > max_z: max_z = z

    max_dim = max(max_x - min_x, max_y - min_y, max_z - min_z, 1e-6)

    # Search for optimal grid resolution
    low_res = 10
    high_res = 400
    best_result = triangles

    for _ in range(12):
        mid_res = (low_res + high_res) // 2
        cell_size = max_dim / mid_res

        def quantize(pt):
            return (
                round((pt[0] - min_x) / cell_size) * cell_size + min_x,
                round((pt[1] - min_y) / cell_size) * cell_size + min_y,
                round((pt[2] - min_z) / cell_size) * cell_size + min_z,
            )

        new_triangles = []
        seen = set()
        for v1, v2, v3 in triangles:
            qv1 = quantize(v1)
            qv2 = quantize(v2)
            qv3 = quantize(v3)
            # Skip degenerate triangles
            if qv1 == qv2 or qv2 == qv3 or qv3 == qv1:
                continue
            tri_canon = tuple(sorted([qv1, qv2, qv3]))
            if tri_canon in seen:
                continue
            seen.add(tri_canon)
            new_triangles.append((qv1, qv2, qv3))

        count = len(new_triangles)
        if count == 0:
            low_res = mid_res + 1
            continue

        best_result = new_triangles
        if count <= max_limit and count >= max_limit * 0.85:
            break
        if count > max_limit:
            high_res = mid_res - 1
        else:
            low_res = mid_res + 1

    # Guarantee: result strictly <= max_limit
    if len(best_result) > max_limit:
        stride = math.ceil(len(best_result) / max_limit)
        best_result = best_result[::stride]
    if len(best_result) > max_limit:
        best_result = best_result[:max_limit]

    return best_result


def process_mesh(triangles, up_axis="z", rx=0.0, ry=0.0, rz=0.0, scale=1.0, target_size=None):
    """
    Transforms mesh:
    1. Coordinate orientation (Z-up to Y-up)
    2. Rotation
    3. Scaling
    4. Centering on (X=0, Z=0)
    5. Grounding on Y = 0 (floor)
    """
    if not triangles:
        raise ValueError("No triangles found in STL model.")

    axis_rx = 0.0
    if up_axis.lower() == "z":
        axis_rx = -90.0
    elif up_axis.lower() == "-z":
        axis_rx = 90.0

    total_rx = rx + axis_rx

    # Step 1: Rotate vertices
    rotated_triangles = []
    for v1, v2, v3 in triangles:
        rv1 = rotate_point(v1, total_rx, ry, rz)
        rv2 = rotate_point(v2, total_rx, ry, rz)
        rv3 = rotate_point(v3, total_rx, ry, rz)
        rotated_triangles.append((rv1, rv2, rv3))

    # Step 2: Calculate bounds
    min_x = min_y = min_z = float("inf")
    max_x = max_y = max_z = float("-inf")

    for v1, v2, v3 in rotated_triangles:
        for x, y, z in (v1, v2, v3):
            if x < min_x: min_x = x
            if x > max_x: max_x = x
            if y < min_y: min_y = y
            if y > max_y: max_y = y
            if z < min_z: min_z = z
            if z > max_z: max_z = z

    dx = max_x - min_x
    dy = max_y - min_y
    dz = max_z - min_z
    max_dim = max(dx, dy, dz, 1e-6)

    # Step 3: Scale
    actual_scale = scale
    if target_size is not None and target_size > 0:
        actual_scale = target_size / max_dim

    # Step 4: Center horizontally and place bottom on Y = 0 (with tiny 0.001 epsilon to prevent clipping)
    center_x = (min_x + max_x) / 2.0
    center_z = (min_z + max_z) / 2.0
    floor_contact_y = min_y
    ground_epsilon = 0.001

    transformed_triangles = []
    final_min_y = float("inf")
    final_max_y = float("-inf")

    final_min_x = final_min_z = float("inf")
    final_max_x = final_max_z = float("-inf")

    for v1, v2, v3 in rotated_triangles:
        t_v1 = (
            (v1[0] - center_x) * actual_scale,
            (v1[1] - floor_contact_y) * actual_scale + ground_epsilon,
            (v1[2] - center_z) * actual_scale,
        )
        t_v2 = (
            (v2[0] - center_x) * actual_scale,
            (v2[1] - floor_contact_y) * actual_scale + ground_epsilon,
            (v2[2] - center_z) * actual_scale,
        )
        t_v3 = (
            (v3[0] - center_x) * actual_scale,
            (v3[1] - floor_contact_y) * actual_scale + ground_epsilon,
            (v3[2] - center_z) * actual_scale,
        )
        transformed_triangles.append((t_v1, t_v2, t_v3))

        for vx, vy, vz in (t_v1, t_v2, t_v3):
            if vx < final_min_x: final_min_x = vx
            if vx > final_max_x: final_max_x = vx
            if vy < final_min_y: final_min_y = vy
            if vy > final_max_y: final_max_y = vy
            if vz < final_min_z: final_min_z = vz
            if vz > final_max_z: final_max_z = vz

    final_dx = final_max_x - final_min_x
    final_dy = final_max_y - final_min_y
    final_dz = final_max_z - final_min_z

    bbox = {
        "min": (final_min_x, final_min_y, final_min_z),
        "max": (final_max_x, final_max_y, final_max_z),
        "dx": final_dx,
        "dy": final_dy,
        "dz": final_dz,
        "max_dim": max(final_dx, final_dy, final_dz, 1e-6),
        "height": final_dy,
    }

    return transformed_triangles, bbox


def calculate_camera_and_light(bbox, fov=70.0, dist_factor=1.5, azimuth_deg=35.0, elevation_deg=22.0):
    """
    Computes camera position, target, and normalized direction vector,
    along with lighting tailored to the model.
    """
    max_dim = bbox["max_dim"]
    height = bbox["height"]

    target = (0.0, height * 0.45, 0.0)

    half_w = bbox["dx"] / 2.0
    half_h = bbox["dy"] / 2.0
    half_d = bbox["dz"] / 2.0
    bounding_radius = math.sqrt(half_w ** 2 + half_h ** 2 + half_d ** 2)
    bounding_radius = max(bounding_radius, max_dim / 2.0)

    fov_rad = math.radians(fov)
    base_dist = bounding_radius / math.sin(fov_rad / 2.0)
    dist = base_dist * dist_factor

    azimuth_rad = math.radians(azimuth_deg)
    elevation_rad = math.radians(elevation_deg)

    cam_x = dist * math.sin(azimuth_rad) * math.cos(elevation_rad)
    cam_y = target[1] + dist * math.sin(elevation_rad)
    cam_z = dist * math.cos(azimuth_rad) * math.cos(elevation_rad)
    cam_pos = (cam_x, cam_y, cam_z)

    raw_dir = (target[0] - cam_x, target[1] - cam_y, target[2] - cam_z)
    norm_dir = normalize_vector(raw_dir)

    # MiniRT normal length check (fabs(len - 1.0) <= 1e-6)
    d_x, d_y, d_z = norm_dir
    formatted_dir = f"{d_x:.7f},{d_y:.7f},{d_z:.7f}"
    px, py, pz = [float(c) for c in formatted_dir.split(",")]
    plen = math.sqrt(px * px + py * py + pz * pz)
    if abs(plen - 1.0) > 1e-6:
        factor = 1.0 / plen
        formatted_dir = f"{px * factor:.7f},{py * factor:.7f},{pz * factor:.7f}"

    light_x = -dist * 0.5
    light_y = height + dist * 0.8
    light_z = dist * 0.5
    light_pos = (light_x, light_y, light_z)

    return {
        "cam_pos": cam_pos,
        "cam_dir_str": formatted_dir,
        "cam_fov": fov,
        "light_pos": light_pos,
        "light_brightness": 0.75,
    }


def fmt_coord(n):
    """Formats coordinate to 2 decimal places, removing unnecessary trailing zeros."""
    s = f"{n:.2f}"
    if "." in s:
        s = s.rstrip("0").rstrip(".")
    return "0" if s == "-0" else s


def generate_rt_scene(
    triangles,
    bbox,
    cam_info,
    mesh_color="220,180,140",
    floor_color="160,160,160",
    ambient_ratio=0.25,
    checker_floor=False,
):
    """Generates clean .rt file content without comments."""
    lines = []

    # Ambient light: A <ratio> <R,G,B>
    lines.append(f"A\t{ambient_ratio:.2f}\t255,255,255")
    lines.append("")

    # Camera: C <pos> <dir> <fov>
    cx, cy, cz = cam_info["cam_pos"]
    lines.append(f"C\t{fmt_coord(cx)},{fmt_coord(cy)},{fmt_coord(cz)}\t{cam_info['cam_dir_str']}\t{cam_info['cam_fov']:.1f}")
    lines.append("")

    # Light: L <pos> <brightness> <R,G,B>
    lx, ly, lz = cam_info["light_pos"]
    lines.append(f"L\t{fmt_coord(lx)},{fmt_coord(ly)},{fmt_coord(lz)}\t{cam_info['light_brightness']:.2f}\t255,255,255")
    lines.append("")

    # Ground Plane: pl <pos> <normal> <color>
    if checker_floor:
        lines.append(f"pl\t0,0,0\t0,1,0\t{floor_color}\tchecker\t255,255,255\t60,60,60")
    else:
        lines.append(f"pl\t0,0,0\t0,1,0\t{floor_color}")
    lines.append("")

    # Triangles: tr <p1> <p2> <p3> <color>
    for v1, v2, v3 in triangles:
        p1 = f"{fmt_coord(v1[0])},{fmt_coord(v1[1])},{fmt_coord(v1[2])}"
        p2 = f"{fmt_coord(v2[0])},{fmt_coord(v2[1])},{fmt_coord(v2[2])}"
        p3 = f"{fmt_coord(v3[0])},{fmt_coord(v3[1])},{fmt_coord(v3[2])}"
        lines.append(f"tr\t{p1}\t{p2}\t{p3}\t{mesh_color}")

    return "\n".join(lines) + "\n"


def main():
    parser = argparse.ArgumentParser(
        description="Convert 3D .stl files to miniRT scene files (max 10,000 triangles)."
    )
    parser.add_argument("input_stl", help="Path to input .stl file (ASCII or Binary)")
    parser.add_argument(
        "output_rt",
        nargs="?",
        default=None,
        help="Path to output .rt file (defaults to <input_name>.rt)",
    )
    parser.add_argument(
        "--max-triangles",
        "-n",
        type=int,
        default=DEFAULT_MAX_TRIANGLES,
        help=f"Maximum number of triangles (default: {DEFAULT_MAX_TRIANGLES}). Models with more triangles are reduced to this limit.",
    )
    parser.add_argument(
        "--up",
        choices=["z", "y", "-z", "-y"],
        default="z",
        help="Vertical 'Up' axis of the STL model. Default is 'z'.",
    )
    parser.add_argument(
        "--scale",
        type=float,
        default=1.0,
        help="Uniform scaling factor (default: 1.0).",
    )
    parser.add_argument(
        "--target-size",
        type=float,
        default=None,
        help="Scale model automatically so its largest dimension equals this value (e.g. 15.0).",
    )
    parser.add_argument(
        "--color",
        default="220,180,140",
        help="RGB color for the mesh (default: '220,180,140').",
    )
    parser.add_argument(
        "--floor-color",
        default="160,160,160",
        help="RGB color for the ground plane (default: '160,160,160').",
    )
    parser.add_argument(
        "--checker-floor",
        action="store_true",
        help="Use checkerboard pattern on the ground plane (miniRT bonus).",
    )
    parser.add_argument(
        "--fov",
        type=float,
        default=70.0,
        help="Camera field of view in degrees (default: 70.0).",
    )

    args = parser.parse_args()

    output_path = args.output_rt
    if not output_path:
        base_name = os.path.splitext(args.input_stl)[0]
        output_path = base_name + ".rt"

    print(f"Reading STL file: {args.input_stl}...")
    try:
        raw_triangles = parse_stl(args.input_stl)
    except Exception as e:
        print(f"Error reading STL: {e}", file=sys.stderr)
        sys.exit(1)

    orig_count = len(raw_triangles)
    print(f"Loaded {orig_count} original triangles from STL.")

    max_limit = args.max_triangles if args.max_triangles is not None else DEFAULT_MAX_TRIANGLES

    # Enforce limit: at most 10,000 triangles (never more)
    if orig_count > max_limit:
        print(f"Model has {orig_count} triangles (> {max_limit}). Reducing to <= {max_limit} triangles...")
        simplified_triangles = simplify_mesh(raw_triangles, max_limit=max_limit)
        print(f"Final triangle count: {len(simplified_triangles)} (<= {max_limit})")
    else:
        print(f"Model has {orig_count} triangles (<= {max_limit}). Keeping 100% of original detail.")
        simplified_triangles = raw_triangles

    # Process and ground mesh
    triangles, bbox = process_mesh(
        simplified_triangles,
        up_axis=args.up,
        scale=args.scale,
        target_size=args.target_size,
    )

    print(f"Mesh dimensions: W={bbox['dx']:.2f}, H={bbox['dy']:.2f}, D={bbox['dz']:.2f}")
    print(f"Grounded on floor: min_y = {bbox['min'][1]:.3f} (rests on ground at Y=0)")

    # Compute camera & lighting
    cam_info = calculate_camera_and_light(bbox, fov=args.fov)
    cx, cy, cz = cam_info["cam_pos"]
    print(f"Camera position: ({cx:.2f}, {cy:.2f}, {cz:.2f}), FOV: {cam_info['cam_fov']}")

    # Generate RT content
    rt_content = generate_rt_scene(
        triangles,
        bbox,
        cam_info,
        mesh_color=args.color,
        floor_color=args.floor_color,
        checker_floor=args.checker_floor,
    )

    with open(output_path, "w", encoding="utf-8") as f:
        f.write(rt_content)

    print(f"Successfully generated clean .rt scene file: {output_path} ({len(triangles)} triangles)")


if __name__ == "__main__":
    main()
