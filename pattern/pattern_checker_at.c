/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_checker_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhoura <ralhoura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 18:04:21 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/05 17:20:48 by ralhoura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

t_color	sphere_checker_at(t_pattern *pattern, t_point point)
{
	double	radius;
	double	val;
	long	latitude_cell;
	long	longitude_cell;

	radius = sqrt(point.x * point.x + point.y * point.y + point.z * point.z);
	if (radius < EPSILON)
		return (pattern->color_a);
	val = point.y / radius;
	if (val < -1.0)
		val = -1.0;
	else if (val > 1.0)
		val = 1.0;
	latitude_cell = (long)floor((acos(val) / M_PI) * SPHERE_CHECKER_SIZE);
	longitude_cell = (long)floor(((atan2(point.x, point.z) + M_PI) / (2.0
					* M_PI)) * (2 * SPHERE_CHECKER_SIZE));
	if (latitude_cell >= SPHERE_CHECKER_SIZE)
		latitude_cell = SPHERE_CHECKER_SIZE - 1;
	if (longitude_cell >= 2 * SPHERE_CHECKER_SIZE)
		longitude_cell = (2 * SPHERE_CHECKER_SIZE) - 1;
	if ((latitude_cell + longitude_cell) % 2 == 0)
		return (pattern->color_a);
	return (pattern->color_b);
}

t_color	cylinder_checker_at_axis(t_pattern *pattern, t_point point, t_vec axis,
		double height)
{
	t_vec	radial_x;
	t_vec	radial_z;
	t_vec	radial;
	double	axial;

	radial_basis(axis, &radial_x, &radial_z);
	radial = (t_vec){point.x, point.y, point.z};
	axial = vec_dot(radial, axis);
	radial = vec_sub(radial, vec_scale(axis, axial));
	if (fabs(axial) >= (height / 2.0) - EPSILON)
	{
		if (((long)floor(vec_dot(radial, radial_x) * 2.0)
				+ (long)floor(vec_dot(radial, radial_z) * 2.0)) % 2 == 0)
			return (pattern->color_a);
		return (pattern->color_b);
	}
	else if (((long)floor((atan2(vec_dot(radial, radial_x), vec_dot(radial,
							radial_z)) + M_PI) / (2.0 * M_PI) * CYL_U_SIZE)
			+ (long)floor(axial * CYL_V_SIZE)) % 2 == 0)
		return (pattern->color_a);
	return (pattern->color_b);
}

t_color	plane_checker_at(t_pattern *pattern, t_point point, t_vec normal)
{
	t_vec	tangent;
	t_vec	bitangent;
	t_vec	point_vec;
	t_vec	reference;

	if (fabs(normal.z) < 0.9)
		reference = (t_vec){0.0, 0.0, 1.0};
	else
		reference = (t_vec){0.0, 1.0, 0.0};
	tangent = vec_normalize(vec_cross(normal, reference));
	bitangent = vec_normalize(vec_cross(tangent, normal));
	point_vec = (t_vec){point.x, point.y, point.z};
	if (((long)floor(vec_dot(point_vec, tangent) * PLANE_SCALE)
			+ (long)floor(vec_dot(point_vec, bitangent) * PLANE_SCALE))
		% 2 == 0)
		return (pattern->color_a);
	return (pattern->color_b);
}

t_color	triangle_checker_at_normal(t_pattern *pattern, t_point point,
		t_vec normal)
{
	t_vec	tangent;
	t_vec	bitangent;
	t_vec	value;
	long	cell_x;
	long	cell_y;

	radial_basis(normal, &tangent, &bitangent);
	value = (t_vec){point.x, point.y, point.z};
	cell_x = (long)floor(vec_dot(value, tangent) * TRI_SCALE);
	cell_y = (long)floor(vec_dot(value, bitangent) * TRI_SCALE);
	if ((cell_x + cell_y) % 2 == 0)
		return (pattern->color_a);
	return (pattern->color_b);
}

t_color	paraboloid_checker_at_axis(t_pattern *pattern, t_point point,
		t_vec axis, double height)
{
	t_vec	radial_x;
	t_vec	radial_z;
	t_vec	radial;
	double	axial;

	radial_basis(axis, &radial_x, &radial_z);
	radial = (t_vec){point.x, point.y, point.z};
	axial = vec_dot(radial, axis);
	radial = vec_sub(radial, vec_scale(axis, axial));
	if (((long)floor(((atan2(vec_dot(radial, radial_x), vec_dot(radial,
								radial_z)) + M_PI) / (2.0 * M_PI)) * 8.0)
			+ (long)floor((axial / height) * PARA_SCALE)) % 2 == 0)
		return (pattern->color_a);
	return (pattern->color_b);
}
