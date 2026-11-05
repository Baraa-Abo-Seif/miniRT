*This project has been created as part of the 42 curriculum by babo-sai,ralhoura.*

# miniRT

## Description

miniRT is a small 3D ray tracer written in C as part of the 42 curriculum. It
parses a scene description, builds a world containing a camera, lights, and
geometric objects, then renders the result in a window using MiniLibX.

The project is designed to make the complete rendering pipeline explicit:
scene parsing and validation, vector and color mathematics, ray generation,
ray-object intersections, surface shading, shadows, reflections, patterns,
texture mapping, and bump mapping.

Supported primitives include:

- spheres;
- planes;
- finite cylinders, including end caps;
- triangles;
- paraboloids.

The renderer also supports multiple lights, diffuse and specular lighting,
shadows, reflective materials, checker patterns, image textures, and bump
maps where the corresponding scene data and image assets are available.

## Project Statistics

- **10,764 lines of code**
- **196 files**
- **35 folders**

## Features

- Strict `.rt` scene parsing with tokenization, argument validation, and
  semantic validation.
- Normalized camera and object direction vectors.
- Ambient, diffuse, specular, and multi-light illumination.
- Shadow rays and reflective surfaces.
- Sphere, plane, cylinder, triangle, and paraboloid intersection routines.
- Checkerboard patterns and UV mapping.
- XPM color textures and bump-map normal perturbation.
- MiniLibX event handling and window cleanup.
- Dependency-aware incremental builds through the root Makefile.

## Requirements

- Linux with an X11 display.
- A C compiler supporting the project flags (`cc` or `clang`).
- `make`.
- X11 development libraries, including `libXext` and `libX11`.
- Math library support (`libm`).

MiniLibX and Libft are included in the repository. No external package
manager is required for the project itself.

## Instructions

### Compilation

From the repository root:

```sh
make
```

The executable is created as `./miniRT`. The build also compiles the bundled
Libft and MiniLibX libraries.

Useful targets:

```sh
make        # Build miniRT and its libraries
make clean  # Remove object files and the build directory
make fclean # Remove objects, libraries, build files, and the executable
make re     # Full clean rebuild
```

### Execution

Run one scene file at a time:

```sh
./miniRT path/to/scene.rt
```

For example:

```sh
./miniRT all_test/bouns/01_checkerboard_spheres.rt
./miniRT all_test/bouns/08_bump_map_full.rt
```

The program requires exactly one argument, and that argument must have the
`.rt` extension. Close the render window with the configured close event or
the Escape key.

### Scene format

A scene normally contains one ambient-light record (`A`), one camera record
(`C`), at least one light (`L` or `l`), and one or more objects. Common object
records are:

```text
A 0.2 255,255,255
C 0,20,-40 0,-0.37139068,0.92847669 70
L 50,10,-50 1.0 255,255,255
sp 0,0,50 20 255,0,0
pl 0,-10,0 0,1,0 255,255,255
cy 0,0,50 0,1,0 10 20 0,255,255
tr 0,0,50 10,0,50 0,10,50 255,255,255
```

Camera, plane, and cylinder direction vectors must be normalized. Positive
dimensions and valid color values are required. Optional material and
texture data must follow the syntax implemented by the parser.

## Repository layout

| Path | Purpose |
| --- | --- |
| `main.c`, `minirt.h` | Program entry point and project-wide includes. |
| `Makefile` | Root build, dependency, clean, and link rules. |
| `parser/` | Scene file reading, lexing, conversion, validation, and builders. |
| `scene/` | Scene, camera, light, object, and texture data structures. |
| `intersector/` | Ray intersections and hit-record calculations. |
| `renderer/` | Camera rays, shading, shadows, reflection, and image rendering. |
| `lib_math/` | Vector, point, ray, and color operations. |
| `texture/` | UV mapping, tangent bases, XPM loading, and bump mapping. |
| `pattern/` | Procedural checkerboard pattern support. |
| `get_next_line/` | Line-oriented file input used by the parser. |
| `libft/` | Bundled 42 Libft implementation and its build files. |
| `assets/` | XPM assets used by texture and bump-map scenes. |
| `all_test/` | Valid, invalid, mandatory, and bonus regression `.rt` scenes. |

## Testing

The repository contains many `.rt` scenes under `all_test/`, `new_test/`, and
`ttt/`. They are integration scenes: each one is run with `miniRT`, validated
by the parser, and displayed by the renderer.

Because miniRT is an interactive graphical program, a test run must have an
available X11 display and should be closed after the scene has been inspected.
The scene files are also useful for focused checks of cylinders, triangles,
paraboloids, shadows, specular highlights, patterns, textures, and bump maps.

## License

This repository is an educational 42 project. The bundled MiniLibX and Libft
components retain their respective upstream or school-project licensing and
copyright notices.

## Detailed C and Header File Reference

This section documents every `.c` and `.h` file in the repository. Header
files define the data structures and interfaces used by the implementation;
source files contain the corresponding logic. The generated `.o` files and
static libraries are build outputs and are not listed as source files.

### Application entry point

- [`main.c`](./main.c): validates the command-line
  argument, requires a `.rt` scene path, calls the parser, starts the
  renderer, and destroys the scene on exit.
- [`minirt.h`](./minirt.h): umbrella header that
  includes the parser, renderer, scene, intersection, texture, utility,
  Libft, MiniLibX, and standard-library interfaces.

### `get_next_line`

- [`get_next_line.c`](./get_next_line/get_next_line.c):
  reads one line at a time from a file descriptor while preserving unread
  buffered data between calls.
- [`get_next_line_utils.c`](./get_next_line/get_next_line_utils.c):
  provides string and buffer helpers used by the mandatory line reader.
- [`get_next_line.h`](./get_next_line/get_next_line.h):
  declares the mandatory `get_next_line` API and its buffer configuration.
- [`get_next_line_bonus.c`](./get_next_line/get_next_line_bonus.c):
  provides the multi-file-descriptor version of the line reader.
- [`get_next_line_utils_bonus.c`](./get_next_line/get_next_line_utils_bonus.c):
  contains helpers for the bonus reader's per-descriptor buffers.
- [`get_next_line_bonus.h`](./get_next_line/get_next_line_bonus.h):
  declares the bonus line-reader interface.

### `scene`

- [`scene.h`](./scene/scene.h): defines the complete
  scene container, including ambient light, camera, lights, and object list.
- [`ambient.h`](./scene/ambient.h): defines ambient
  light intensity and color.
- [`camera.h`](./scene/camera.h): defines camera
  position, normalized forward direction, and field of view.
- [`light.h`](./scene/light.h): defines a light's
  position, brightness, color, and linked-list relationship.
- [`object.h`](./scene/object.h): defines the common
  object structure, material data, object type, transformations, and union of
  primitive-specific data.
- [`objects/sphere.h`](./scene/objects/sphere.h):
  stores sphere center and radius.
- [`objects/plane.h`](./scene/objects/plane.h):
  stores plane position and normal.
- [`objects/cylinder.h`](./scene/objects/cylinder.h):
  stores cylinder center, axis, radius, and height.
- [`objects/triangle.h`](./scene/objects/triangle.h):
  stores the three triangle vertices.
- [`objects/paraboloid.h`](./scene/objects/paraboloid.h):
  stores paraboloid position, axis, diameter, and height.
- [`texture_data.h`](./scene/texture_data.h):
  defines UV coordinates, tangent-basis data, loaded image data, bump-map
  configuration, and color-texture configuration.

### `lib_math`

#### Math headers

- [`lib_math.h`](./lib_math/lib_math.h): central
  include for vector, point, ray, and color modules.
- [`vector.h`](./lib_math/vector/vector.h): declares
  vector arithmetic, length, normalization, dot, cross, reflection, and scale.
- [`point.h`](./lib_math/point/point.h): declares
  point/vector conversions and point arithmetic.
- [`ray.h`](./lib_math/ray/ray.h): defines rays and
  declares evaluation along a ray.
- [`color.h`](./lib_math/color/color.h): defines color
  values and declares color arithmetic and conversion helpers.

#### Vector, point, ray, and color implementations

- [`vector/vec_add.c`](./lib_math/vector/vec_add.c):
  adds two vectors component by component.
- [`vector/vec_sub.c`](./lib_math/vector/vec_sub.c):
  subtracts one vector from another.
- [`vector/vec_scale.c`](./lib_math/vector/vec_scale.c):
  multiplies a vector by a scalar.
- [`vector/vec_dot.c`](./lib_math/vector/vec_dot.c):
  computes the scalar dot product.
- [`vector/vec_cross.c`](./lib_math/vector/vec_cross.c):
  computes a perpendicular cross-product vector.
- [`vector/vec_length.c`](./lib_math/vector/vec_length.c):
  computes Euclidean vector length.
- [`vector/vec_normalize.c`](./lib_math/vector/vec_normalize.c):
  returns a unit vector while guarding the zero-length case.
- [`vector/vec_distance.c`](./lib_math/vector/vec_distance.c):
  computes the distance between two vector-valued positions.
- [`vector/vec_reflect.c`](./lib_math/vector/vec_reflect.c):
  reflects an incoming vector around a surface normal.
- [`point/point_add_vec.c`](./lib_math/point/point_add_vec.c):
  translates a point by a vector.
- [`point/point_sub_point.c`](./lib_math/point/point_sub_point.c):
  returns the vector between two points.
- [`point/point_sub_vec.c`](./lib_math/point/point_sub_vec.c):
  translates a point in the opposite direction of a vector.
- [`ray/ray_at.c`](./lib_math/ray/ray_at.c):
  evaluates `origin + direction * t`.
- [`color/color_add.c`](./lib_math/color/color_add.c):
  adds RGB/color components.
- [`color/color_multiply.c`](./lib_math/color/color_multiply.c):
  performs component-wise color multiplication for lighting.
- [`color/color_scale.c`](./lib_math/color/color_scale.c):
  scales a color by a brightness factor.
- [`color/color_clamp.c`](./lib_math/color/color_clamp.c):
  clamps color channels to the renderer's valid range.
- [`color/color_clamp_rgb.c`](./lib_math/color/color_clamp_rgb.c):
  clamps individual RGB channels before display.
- [`color/color_to_hex.c`](./lib_math/color/color_to_hex.c):
  converts floating-point color data to MiniLibX pixel format.

### `parser`

#### Parser interfaces

- [`parser.h`](./parser/parser.h): exposes the
  top-level scene parsing function.
- [`builder/builder.h`](./parser/builder/builder.h):
  declares scene, light, camera, and object builders.
- [`builder/objects/object_builder.h`](./parser/builder/objects/object_builder.h):
  declares primitive builders and optional-object-property parsing.
- [`converter/converter.h`](./parser/converter/converter.h):
  declares numeric, point, vector, and color conversion functions.
- [`lexer/lexer_token.h`](./parser/lexer/lexer_token.h):
  defines token types and the token linked-list structure.
- [`validator/validator.h`](./parser/validator/validator.h):
  declares token, argument-count, and scene-rule validation.
- [`parsering_utils/parsing_utils.h`](./parser/parsering_utils/parsing_utils.h):
  declares file, ratio, positivity, normal, and string-array checks.

#### Parser pipeline

- [`parser.c`](./parser/parser.c): coordinates file
  reading, tokenization, validation, scene construction, and cleanup on error.
- [`lexer/tokenize.c`](./parser/lexer/tokenize.c):
  splits each input line into an identifier and arguments.
- [`lexer/create_token.c`](./parser/lexer/create_token.c):
  allocates and initializes a token with its source line number.
- [`lexer/copy_args.c`](./parser/lexer/copy_args.c):
  copies token arguments into an owned string array.
- [`lexer/get_token_type.c`](./parser/lexer/get_token_type.c):
  maps identifiers such as `A`, `C`, `L`, `sp`, `pl`, `cy`, `tr`, and `pa` to
  internal token types.
- [`lexer/lexer_utils.c`](./parser/lexer/lexer_utils.c):
  supplies whitespace and token-string helpers.
- [`lexer/destroy_token_list.c`](./parser/lexer/destroy_token_list.c):
  releases token nodes and their argument arrays.
- [`parsering_utils/read_file.c`](./parser/parsering_utils/read_file.c):
  opens a scene file and feeds its lines to the tokenizer.
- [`parsering_utils/free_string_array.c`](./parser/parsering_utils/free_string_array.c):
  frees NULL-terminated string arrays.

#### Parser conversion and validation

- [`converter/parse_color.c`](./parser/converter/parse_color.c):
  parses and validates comma-separated RGB values.
- [`converter/parse_double.c`](./parser/converter/parse_double.c):
  converts a numeric token to a double.
- [`converter/parse_point.c`](./parser/converter/parse_point.c):
  parses three coordinates as a point.
- [`converter/parse_vector.c`](./parser/converter/parse_vector.c):
  parses three coordinates as a vector.
- [`converter/utils.c`](./parser/converter/utils.c):
  provides conversion error and component-splitting helpers.
- [`validator/validator.c`](./parser/validator/validator.c):
  runs all validation stages in the required order.
- [`validator/validate_token_types.c`](./parser/validator/validate_token_types.c):
  rejects unknown line identifiers.
- [`validator/validate_arg_count.c`](./parser/validator/validate_arg_count.c):
  verifies the required argument count for every token type.
- [`validator/validate_scene_rules.c`](./parser/validator/validate_scene_rules.c):
  enforces required ambient, camera, and light records and uniqueness rules.
- [`validator/validator_utils.c`](./parser/validator/validator_utils.c):
  stores expected argument counts and scene-counting helpers.
- [`parsering_utils/check_normal.c`](./parser/parsering_utils/check_normal.c):
  checks that directions have unit length.
- [`parsering_utils/check_positive.c`](./parser/parsering_utils/check_positive.c):
  rejects zero or negative dimensions and intensities.
- [`parsering_utils/check_ratio.c`](./parser/parsering_utils/check_ratio.c):
  checks brightness and ratio limits.

#### Scene builders

- [`builder/build_scene.c`](./parser/builder/build_scene.c):
  iterates over validated tokens and builds the complete scene.
- [`builder/builder_utils.c`](./parser/builder/builder_utils.c):
  appends objects and lights to linked lists and dispatches token processing.
- [`builder/build_ambient.c`](./parser/builder/build_ambient.c):
  builds ambient ratio and color.
- [`builder/build_camera.c`](./parser/builder/build_camera.c):
  builds and validates camera position, direction, and FOV.
- [`builder/build_light.c`](./parser/builder/build_light.c):
  builds a light and validates brightness and color.
- [`builder/build_object.c`](./parser/builder/build_object.c):
  dispatches an object token to its primitive builder.
- [`builder/objects/create_object.c`](./parser/builder/objects/create_object.c):
  allocates an object and initializes default material/texture state.
- [`builder/objects/objects_utils.c`](./parser/builder/objects/objects_utils.c):
  provides object initialization and failed-build cleanup helpers.
- [`builder/objects/build_sphere.c`](./parser/builder/objects/build_sphere.c):
  reads sphere center, diameter/radius, color, and optional material data.
- [`builder/objects/build_plane.c`](./parser/builder/objects/build_plane.c):
  reads plane position, normal, color, and optional properties.
- [`builder/objects/build_cylinder.c`](./parser/builder/objects/build_cylinder.c):
  reads cylinder position, axis, diameter, height, color, and material data.
- [`builder/objects/build_triangle.c`](./parser/builder/objects/build_triangle.c):
  reads three vertices, color, and optional material data.
- [`builder/objects/build_paraboloid.c`](./parser/builder/objects/build_paraboloid.c):
  reads paraboloid position, axis, diameter, height, color, and properties.
- [`builder/objects/parse_object_bonus.c`](./parser/builder/objects/parse_object_bonus.c):
  parses checker patterns, color textures, bump-map paths, intensities, and
  other optional material values.

### `intersector`

- [`intersector.h`](./intersector/intersector.h):
  central declarations for all ray-object intersection routines.
- [`hit/hit_record.h`](./intersector/hit/hit_record.h):
  defines the intersection result, hit distance, point, normal, and object.
- [`hit/object_dispatch.c`](./intersector/hit/object_dispatch.c):
  selects the correct primitive intersection implementation.
- [`hit/world_hit.c`](./intersector/hit/world_hit.c):
  tests all scene objects and retains the closest valid hit.
- [`hit/hit_record_set_face_normal.c`](./intersector/hit/hit_record_set_face_normal.c):
  orients a surface normal against or away from the incoming ray.
- [`sphere/sphere_hit.c`](./intersector/sphere/sphere_hit.c):
  solves the quadratic sphere intersection equation.
- [`sphere/sphere_hit.h`](./intersector/sphere/sphere_hit.h):
  declares sphere intersection functions.
- [`plane/plane_hit.c`](./intersector/plane/plane_hit.c):
  solves the plane intersection using the ray/normal dot product.
- [`plane/plane_hit.h`](./intersector/plane/plane_hit.h):
  declares plane intersection functions.
- [`cylinder/cylinder_body.c`](./intersector/cylinder/cylinder_body.c):
  intersects a ray with the finite cylindrical body and limits hits by height.
- [`cylinder/cylinder_caps.c`](./intersector/cylinder/cylinder_caps.c):
  intersects the two circular end caps.
- [`cylinder/cylinder_hit.h`](./intersector/cylinder/cylinder_hit.h):
  declares cylinder body and cap routines.
- [`triangle/triangle_hit.c`](./intersector/triangle/triangle_hit.c):
  uses barycentric-style edge tests to intersect a triangle.
- [`triangle/triangle_hit.h`](./intersector/triangle/triangle_hit.h):
  declares triangle intersection functions.
- [`paraboloid/paraboloid_hit.c`](./intersector/paraboloid/paraboloid_hit.c):
  solves the ray/paraboloid equation and constrains the finite shape.
- [`paraboloid/paraboloid_hit.h`](./intersector/paraboloid/paraboloid_hit.h):
  declares paraboloid intersection functions.

### `renderer`

- [`renderer.h`](./renderer/renderer.h): declares the
  rendering, shading, shadow, and color pipeline.
- [`run_renderer.c`](./renderer/run_renderer.c):
  initializes the display and image, renders the scene, registers events, and
  enters the MiniLibX loop.
- [`render.c`](./renderer/render.c): iterates over
  image pixels, creates camera rays, calculates colors, and writes pixels.
- [`ray_color.c`](./renderer/ray_color.c): traces a
  ray, returns background or shaded hit color, and handles reflection.
- [`shade_hit.c`](./renderer/shade_hit.c): combines
  material, ambient, diffuse, specular, shadow, texture, and reflection data.
- [`ambient.c`](./renderer/ambient.c): applies the
  scene ambient contribution to a surface color.
- [`diffuse.c`](./renderer/diffuse.c): computes
  diffuse light according to normal/light direction and light color.
- [`specular_bonus.c`](./renderer/specular_bonus.c):
  computes optional specular highlights and material response.
- [`is_in_shadow.c`](./renderer/is_in_shadow.c):
  sends a ray toward a light and checks whether another object blocks it.
- [`camera/renderer_camera.h`](./renderer/camera/renderer_camera.h):
  declares camera-rendering state and viewport helpers.
- [`camera/camera_init.c`](./renderer/camera/camera_init.c):
  initializes render-camera state from the scene camera.
- [`camera/camera_build_basis.c`](./renderer/camera/camera_build_basis.c):
  constructs orthogonal right, up, and forward camera basis vectors.
- [`camera/camera_compute_viewport.c`](./renderer/camera/camera_compute_viewport.c):
  calculates viewport dimensions from FOV and image aspect ratio.
- [`camera/camera_compute_pixel_delta.c`](./renderer/camera/camera_compute_pixel_delta.c):
  calculates horizontal and vertical increments between pixel samples.
- [`camera/camera_ray.c`](./renderer/camera/camera_ray.c):
  creates a world-space ray through a requested pixel.

### `pattern`

- [`pattern.h`](./pattern/pattern.h): defines pattern
  types, pattern colors, and pattern interfaces.
- [`pattern_checker_at.c`](./pattern/pattern_checker_at.c):
  selects alternating checker colors from a surface location.
- [`helper.c`](./pattern/helper.c): provides pattern
  coordinate and color helper operations.

### `texture`

- [`texture.h`](./texture/texture.h): declares image,
  UV, TBN, texture, and bump-map operations.
- [`texture_loader.c`](./texture/texture_loader.c):
  loads XPM files with MiniLibX and stores image pixel metadata.
- [`uv_mapping.c`](./texture/uv_mapping.c):
  converts surface hit positions to two-dimensional UV coordinates.
- [`tbn_basis.c`](./texture/tbn_basis.c):
  builds tangent, bitangent, and normal vectors for texture-space sampling.
- [`compute_object_tbn_uv_for_each_object.c`](./texture/compute_object_tbn_uv_for_each_object.c):
  selects object-specific TBN and UV calculations.
- [`bump_map.c`](./texture/bump_map.c):
  samples bump-map height differences and perturbs the hit normal.
- [`helper_textuer.c`](./texture/helper_textuer.c):
  contains shared texture loading, sampling, and cleanup helpers.

### `mlx_engine`

- [`mlx_api.h`](./mlx_engine/mlx_api.h): project-level
  MiniLibX API declarations used by the engine wrapper.
- [`display/mlx_display.h`](./mlx_engine/display/mlx_display.h):
  declares image-to-window display operations.
- [`display/mlx_display_image.c`](./mlx_engine/display/mlx_display_image.c):
  pushes the rendered image to the MiniLibX window.
- [`window/mlx_window.h`](./mlx_engine/window/mlx_window.h):
  declares window creation and destruction.
- [`window/mlx_window_create.c`](./mlx_engine/window/mlx_window_create.c):
  creates the render window.
- [`window/mlx_window_destroy.c`](./mlx_engine/window/mlx_window_destroy.c):
  releases the render window.
- [`image/mlx_image.h`](./mlx_engine/image/mlx_image.h):
  declares image allocation and pixel-buffer operations.
- [`image/mlx_image_create.c`](./mlx_engine/image/mlx_image_create.c):
  creates a MiniLibX image.
- [`image/mlx_image_data.c`](./mlx_engine/image/mlx_image_data.c):
  obtains the image address, stride, bit depth, and endian information.
- [`image/mlx_image_destroy.c`](./mlx_engine/image/mlx_image_destroy.c):
  destroys the image and releases its resources.
- [`pixel/mlx_pixel.h`](./mlx_engine/pixel/mlx_pixel.h):
  declares pixel-writing helpers.
- [`pixel/mlx_image_pixel_put.c`](./mlx_engine/pixel/mlx_image_pixel_put.c):
  writes a packed color into the image buffer.
- [`events/mlx_event.h`](./mlx_engine/events/mlx_event.h):
  declares keyboard, close, expose, and loop event handlers.
- [`events/mlx_event_init.c`](./mlx_engine/events/mlx_event_init.c):
  installs the application's MiniLibX hooks.
- [`events/mlx_event_key.c`](./mlx_engine/events/mlx_event_key.c):
  handles keyboard input, including the Escape exit path.
- [`events/mlx_event_close.c`](./mlx_engine/events/mlx_event_close.c):
  handles window-close events and cleanup.
- [`events/mlx_event_expose.c`](./mlx_engine/events/mlx_event_expose.c):
  redraws the image after an expose event.
- [`events/mlx_event_loop.c`](./mlx_engine/events/mlx_event_loop.c):
  starts or controls the MiniLibX event loop.

### `utils`

- [`utils.h`](./utils/utils.h): declares error and
  scene/resource cleanup functions.
- [`error.c`](./utils/error.c): prints consistent
  parser and runtime error messages.
- [`destroy_scene.c`](./utils/destroy_scene.c):
  frees all scene objects, lights, textures, and scene-level memory.
- [`destroy_texture.c`](./utils/destroy_texture.c):
  releases loaded texture resources and associated image data.

### Bundled `libft`

The files in [`libft/`](./libft) implement the
standard 42 Libft support library used by parsing and memory management:

- [`libft.h`](./libft/libft.h): declares the complete
  Libft API and list structure.
- [`ft_atoi.c`](./libft/ft_atoi.c): converts text to
  an integer.
- [`ft_bzero.c`](./libft/ft_bzero.c): zeros a memory
  region.
- [`ft_calloc.c`](./libft/ft_calloc.c): allocates
  zero-initialized memory.
- [`ft_itoa.c`](./libft/ft_itoa.c): converts an
  integer to allocated text.
- [`ft_isalnum.c`](./libft/ft_isalnum.c):
  checks alphanumeric characters.
- [`ft_isalpha.c`](./libft/ft_isalpha.c): checks
  alphabetic characters.
- [`ft_isascii.c`](./libft/ft_isascii.c): checks the
  ASCII range.
- [`ft_isdigit.c`](./libft/ft_isdigit.c): checks
  decimal digits.
- [`ft_isprint.c`](./libft/ft_isprint.c): checks
  printable characters.
- [`ft_memchr.c`](./libft/ft_memchr.c): searches a
  byte in memory.
- [`ft_memcmp.c`](./libft/ft_memcmp.c): compares
  memory regions.
- [`ft_memcpy.c`](./libft/ft_memcpy.c): copies
  non-overlapping memory.
- [`ft_memmove.c`](./libft/ft_memmove.c): copies
  overlapping memory safely.
- [`ft_memset.c`](./libft/ft_memset.c): fills memory
  with a byte.
- [`ft_putchar_fd.c`](./libft/ft_putchar_fd.c):
  writes one character to a descriptor.
- [`ft_putendl_fd.c`](./libft/ft_putendl_fd.c):
  writes a string followed by a newline.
- [`ft_putnbr_fd.c`](./libft/ft_putnbr_fd.c): writes
  an integer to a descriptor.
- [`ft_putstr_fd.c`](./libft/ft_putstr_fd.c): writes
  a string to a descriptor.
- [`ft_split.c`](./libft/ft_split.c): splits a string
  by a delimiter into an allocated array.
- [`ft_strchr.c`](./libft/ft_strchr.c): finds a
  character in a string.
- [`ft_strdup.c`](./libft/ft_strdup.c): duplicates a
  string.
- [`ft_striteri.c`](./libft/ft_striteri.c): applies a
  callback to each character with its index.
- [`ft_strjoin.c`](./libft/ft_strjoin.c): joins two
  strings.
- [`ft_strlcat.c`](./libft/ft_strlcat.c): performs
  bounded concatenation.
- [`ft_strlcpy.c`](./libft/ft_strlcpy.c): performs
  bounded copying.
- [`ft_strlen.c`](./libft/ft_strlen.c): returns string
  length.
- [`ft_strmapi.c`](./libft/ft_strmapi.c): creates a
  mapped string through a callback.
- [`ft_strncmp.c`](./libft/ft_strncmp.c): compares
  bounded string prefixes.
- [`ft_strnstr.c`](./libft/ft_strnstr.c): searches
  for a substring within a bounded string.
- [`ft_strrchr.c`](./libft/ft_strrchr.c): finds the
  last occurrence of a character.
- [`ft_strtrim.c`](./libft/ft_strtrim.c): removes
  selected characters from both ends of a string.
- [`ft_substr.c`](./libft/ft_substr.c): allocates a
  substring.
- [`ft_tolower.c`](./libft/ft_tolower.c): converts a
  character to lowercase.
- [`ft_toupper.c`](./libft/ft_toupper.c): converts a
  character to uppercase.
- [`ft_lstnew_bonus.c`](./libft/ft_lstnew_bonus.c):
  allocates a list node.
- [`ft_lstadd_front_bonus.c`](./libft/ft_lstadd_front_bonus.c):
  prepends a node.
- [`ft_lstadd_back_bonus.c`](./libft/ft_lstadd_back_bonus.c):
  appends a node.
- [`ft_lstlast_bonus.c`](./libft/ft_lstlast_bonus.c):
  returns the final node.
- [`ft_lstsize_bonus.c`](./libft/ft_lstsize_bonus.c):
  counts nodes.
- [`ft_lstdelone_bonus.c`](./libft/ft_lstdelone_bonus.c):
  deletes one node with a callback.
- [`ft_lstclear_bonus.c`](./libft/ft_lstclear_bonus.c):
  deletes an entire list.
- [`ft_lstiter_bonus.c`](./libft/ft_lstiter_bonus.c):
  applies a callback to every node.
- [`ft_lstmap_bonus.c`](./libft/ft_lstmap_bonus.c):
  maps nodes into a new list.

## Resources

- [Ray Tracing GitHub](https://github.com/raytracing)  Resources and tutorials covering ray tracing, computer graphics, rendering, and related concepts.

- [miniRT:](https://github.com/Baraa-Abo-Seif/miniRT_The_Mathematics_You_Actually_Need) The Mathematics You Actually Need A guide to the essential mathematics behind ray tracing, including vectors, geometry, matrices, and ray intersections.

- [3Blue1Brown Linear Algebra](https://www.3blue1brown.com/?topic=linear-algebra) Visual explanations of linear algebra, vectors, matrices, transformations, and geometric concepts.

### AI usage

AI assistance was used as a development aid, not as a replacement for
understanding or validating the implementation. It was used for:

- navigating the repository and grouping the parser, renderer, math, texture,
  and MiniLibX code;
- reviewing scene-file syntax and identifying invalid or non-normalized values
  in test scenes;
- suggesting documentation structure and improving README wording;
- helping summarize existing source files, project statistics, and test
  results.

All code changes and scene changes were reviewed against the repository's
actual source, Makefile, assets, and runtime behavior. The final behavior is
validated by compiling and launching the project with real `.rt` scenes.
