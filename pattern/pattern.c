#include "pattern.h"
#include <math.h>

#define SPHERE_CHECKER_SIZE 8
#define CYL_U_SIZE 8
#define CYL_V_SIZE 2
#define PLANE_SCALE 0.5
#define TRI_SCALE 2
#define PARA_SCALE 5

static double   clamp_unit(double value)
{
    if (value < -1.0)
        return (-1.0);
    if (value > 1.0)
        return (1.0);
    return (value);
}

static t_vec point_as_vec(t_point point)
{
    return ((t_vec){point.x, point.y, point.z});
}

static void radial_basis(t_vec axis, t_vec *radial_x, t_vec *radial_z)
{
	t_vec reference;

	if (fabs(axis.x) < EPSILON && fabs(axis.z) < EPSILON)
	{
		*radial_x = (t_vec){1.0, 0.0, 0.0};
		*radial_z = (t_vec){0.0, 0.0, 1.0};
		return ;
	}
	if (fabs(axis.y) < 0.9)
		reference = (t_vec){0.0, 1.0, 0.0};
	else
		reference = (t_vec){0.0, 0.0, 1.0};
	*radial_x = vec_normalize(vec_cross(reference, axis));
	*radial_z = vec_normalize(vec_cross(axis, *radial_x));
}

t_color sphere_checker_at(t_pattern *pattern, t_point point)
{
    double  radius;
    double  latitude;
    double  longitude;
    long    latitude_cell;
    long    longitude_cell;

    radius = sqrt(point.x * point.x + point.y * point.y + point.z * point.z);
    if (radius < EPSILON)
        return (pattern->color_a);

    latitude = (acos(clamp_unit(point.y / radius)) / M_PI) * SPHERE_CHECKER_SIZE;
    longitude = ((atan2(point.x, point.z) + M_PI) / (2.0 * M_PI)) * (2 * SPHERE_CHECKER_SIZE);

    latitude_cell = (long)floor(latitude);
    longitude_cell = (long)floor(longitude);

    if (latitude_cell >= SPHERE_CHECKER_SIZE)
        latitude_cell = SPHERE_CHECKER_SIZE - 1;
    if (longitude_cell >= 2 * SPHERE_CHECKER_SIZE)
        longitude_cell = (2 * SPHERE_CHECKER_SIZE) - 1;

    if ((latitude_cell + longitude_cell) % 2 == 0)
        return (pattern->color_a);
    return (pattern->color_b);
}

t_color cylinder_checker_at(t_pattern *pattern, t_point point, double height)
{
    double  u;
    double  v;
    long    u_cell;
    long    v_cell;

    if (fabs(point.y) >= (height / 2.0) - EPSILON)
    {
        u_cell = (long)floor(point.x * 2.0);
        v_cell = (long)floor(point.z * 2.0);
    }

    else
    {
        u = (atan2(point.x, point.z) + M_PI) / (2.0 * M_PI);
        v = point.y;

        u_cell = (long)floor(u * CYL_U_SIZE);
        v_cell = (long)floor(v * CYL_V_SIZE);

        if (u_cell >= CYL_U_SIZE)
            u_cell = CYL_U_SIZE - 1;
    }

    if ((u_cell + v_cell) % 2 == 0)
        return (pattern->color_a);
    return (pattern->color_b);
}

t_color cylinder_checker_at_axis(t_pattern *pattern, t_point point,
				t_vec axis, double height)
{
	t_vec radial_x;
	t_vec radial_z;
	t_vec radial;
	double axial;
	double u;
	long u_cell;
	long v_cell;

	radial_basis(axis, &radial_x, &radial_z);
	radial = (t_vec){point.x, point.y, point.z};
	axial = vec_dot(radial, axis);
	radial = vec_sub(radial, vec_scale(axis, axial));
	if (fabs(axial) >= (height / 2.0) - EPSILON)
	{
		u_cell = (long)floor(vec_dot(radial, radial_x) * 2.0);
		v_cell = (long)floor(vec_dot(radial, radial_z) * 2.0);
	}
	else
	{
		u = (atan2(vec_dot(radial, radial_x),
					vec_dot(radial, radial_z)) + M_PI) / (2.0 * M_PI);
		u_cell = (long)floor(u * CYL_U_SIZE);
		v_cell = (long)floor(axial * CYL_V_SIZE);
	}
	if ((u_cell + v_cell) % 2 == 0)
		return (pattern->color_a);
	return (pattern->color_b);
}



static void plane_basis(t_vec normal, t_vec *tangent, t_vec *bitangent)
{
    t_vec reference;

    if (fabs(normal.z) < 0.9)
        reference = (t_vec){0.0, 0.0, 1.0};
    else
        reference = (t_vec){0.0, 1.0, 0.0};
    *tangent = vec_normalize(vec_cross(normal, reference));
    *bitangent = vec_normalize(vec_cross(*tangent, normal));
}

t_color plane_checker_at(t_pattern *pattern, t_point point, t_vec normal)
{
    t_vec   tangent;
    t_vec   bitangent;
    long    cell_x;
    long    cell_z;

    plane_basis(normal, &tangent, &bitangent);
    cell_x = (long)floor(vec_dot(point_as_vec(point), tangent) * PLANE_SCALE);
    cell_z = (long)floor(vec_dot(point_as_vec(point), bitangent) * PLANE_SCALE);

    if ((cell_x + cell_z) % 2 == 0)
        return (pattern->color_a);
    return (pattern->color_b);
}

t_color triangle_checker_at(t_pattern *pattern, t_point point)
{
    long    cell_x;
    long    cell_y;

    cell_x = (long)floor(point.x * TRI_SCALE);
    cell_y = (long)floor(point.y * TRI_SCALE);

    if ((cell_x + cell_y) % 2 == 0)
        return (pattern->color_a);
    return (pattern->color_b);
}

t_color triangle_checker_at_normal(t_pattern *pattern, t_point point,
				t_vec normal)
{
	t_vec tangent;
	t_vec bitangent;
	t_vec value;
	long cell_x;
	long cell_y;

	radial_basis(normal, &tangent, &bitangent);
	value = point_as_vec(point);
	cell_x = (long)floor(vec_dot(value, tangent) * TRI_SCALE);
	cell_y = (long)floor(vec_dot(value, bitangent) * TRI_SCALE);
	if ((cell_x + cell_y) % 2 == 0)
		return (pattern->color_a);
	return (pattern->color_b);
}

t_color paraboloid_checker_at(t_pattern *pattern, t_point point)
{
    double  u;
    double  v;
    long    u_cell;
    long    v_cell;

    u = (atan2(point.x, point.z) + M_PI) / (2.0 * M_PI);
    v = point.y;

    u_cell = (long)floor(u * 8.0);
    v_cell = (long)floor(v * PARA_SCALE);

    if ((u_cell + v_cell) % 2 == 0)
        return (pattern->color_a);
    return (pattern->color_b);
}

t_color paraboloid_checker_at_axis(t_pattern *pattern, t_point point,
				t_vec axis, double height)
{
	t_vec	radial_x;
	t_vec	radial_z;
	t_vec	radial;
	double	axial;
	long	u_cell;
	long	v_cell;

	radial_basis(axis, &radial_x, &radial_z);
	radial = point_as_vec(point);
	axial = vec_dot(radial, axis);
	radial = vec_sub(radial, vec_scale(axis, axial));
	u_cell = (long)floor(((atan2(vec_dot(radial, radial_x),
					vec_dot(radial, radial_z)) + M_PI)
				/ (2.0 * M_PI)) * 8.0);
	v_cell = (long)floor((axial / height) * PARA_SCALE);
	if ((u_cell + v_cell) % 2 == 0)
		return (pattern->color_a);
	return (pattern->color_b);
}

t_color pattern_at(t_pattern *pattern, t_point point)
{
    if (pattern->type == PATTERN_CHECKER)
        return (plane_checker_at(pattern, point, (t_vec){0.0, 1.0, 0.0}));
    return (pattern->color_a);
}
