/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhoura <ralhoura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 19:58:27 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/05 15:41:31 by ralhoura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

t_uv	sphere_uv(t_point point, t_point center, double radius)
{
	t_vec	d;
	t_uv	uv;
	double	phi;

	d = point_sub_point(point, center);
	if (radius > EPSILON)
		d = vec_scale(d, 1.0 / radius);
	uv.u = (atan2(d.x, d.z) + M_PI) / (2.0 * M_PI);
	if (d.y < -1.0)
		d.y = -1.0;
	else if (d.y > 1.0)
		d.y = 1.0;
	phi = acos(d.y);
	uv.v = phi / M_PI;
	return (uv);
}

t_uv	plane_uv(t_point point, t_point plane_pt, t_vec normal)
{
	t_tbn	tbn;
	t_vec	d;
	t_uv	uv;
	double	u_raw;
	double	v_raw;

	tbn = plane_tbn(normal);
	d = point_sub_point(point, plane_pt);
	u_raw = vec_dot(d, tbn.tangent) * BUMP_PLANE_SCALE;
	v_raw = vec_dot(d, tbn.bitangent) * BUMP_PLANE_SCALE;
	uv.u = u_raw - floor(u_raw);
	uv.v = v_raw - floor(v_raw);
	return (uv);
}

t_uv	cylinder_uv(t_point point, t_point center, t_vec axis, double height)
{
	t_vec	radial;
	t_vec	radial_x;
	t_vec	radial_z;
	t_uv	uv;
	t_vec	reference;

	radial = vec_sub(point_sub_point(point, center), vec_scale(axis,
				vec_dot(point_sub_point(point, center), axis)));
	if (fabs(axis.x) < 0.9)
		reference = (t_vec){1.0, 0.0, 0.0};
	else
		reference = (t_vec){0.0, 1.0, 0.0};
	radial_x = vec_normalize(vec_cross(axis, reference));
	radial_z = vec_normalize(vec_cross(axis, radial_x));
	uv.u = (vec_dot(point_sub_point(point, center), axis) + (height / 2.0))
		/ height;
	uv.v = (atan2(vec_dot(radial, radial_x), vec_dot(radial, radial_z)) + M_PI)
		/ (2.0 * M_PI);
	return (uv_range(uv, 0));
}

t_uv	triangle_uv(t_point point, t_point a, t_point b, t_point c)
{
	t_vec	v0;
	t_vec	v1;
	t_vec	v2;
	double	dots[5];
	t_uv	uv;

	v0 = point_sub_point(b, a);
	v1 = point_sub_point(c, a);
	v2 = point_sub_point(point, a);
	dots[0] = vec_dot(v0, v0);
	dots[1] = vec_dot(v0, v1);
	dots[2] = vec_dot(v1, v1);
	dots[3] = vec_dot(v2, v0);
	dots[4] = vec_dot(v2, v1);
	if (fabs(dots[0] * dots[2] - dots[1] * dots[1]) < EPSILON)
		return ((t_uv){0.0, 0.0});
	uv.u = (dots[2] * dots[3] - dots[1] * dots[4]) / (dots[0] * dots[2]
			- dots[1] * dots[1]);
	uv.v = (dots[0] * dots[4] - dots[1] * dots[3]) / (dots[0] * dots[2]
			- dots[1] * dots[1]);
	return (uv_range(uv, 0));
}

t_uv	paraboloid_uv(t_point point, t_point vertex, t_vec axis, double height)
{
	t_vec	rx;
	t_vec	rz;
	t_vec	radial;
	t_uv	uv;
	t_vec	ref;

	radial = vec_sub(point_sub_point(point, vertex), vec_scale(axis,
				vec_dot(point_sub_point(point, vertex), axis)));
	if (fabs(axis.x) < 0.9)
		ref = (t_vec){1.0, 0.0, 0.0};
	else
		ref = (t_vec){0.0, 1.0, 0.0};
	rx = vec_normalize(vec_cross(axis, ref));
	rz = vec_cross(axis, rx);
	uv.u = (atan2(vec_dot(radial, rx), vec_dot(radial, rz)) + M_PI) / (2.0
			* M_PI);
	if (height > EPSILON)
		uv.v = vec_dot(point_sub_point(point, vertex), axis) / height;
	else
		uv.v = 0.0;
	return (uv_range(uv, 1));
}
