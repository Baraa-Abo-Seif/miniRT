/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_hit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 19:40:49 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/26 19:48:47 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle_hit.h"

bool	calculate_coordinates(t_ray ray, t_triangle_hit *data)
{
	data->u = data->inverse_determinant* vec_dot(data->to_ray,
		data->cross_to_ray_edge_two);
	if (data->u < 0.0 || data->u > 1.0)
		return (false);
	data->cross_to_ray_edge_one = vec_cross(data->to_ray,data->edge_one);
	data->v = data->inverse_determinant* vec_dot(ray.direction,
		data->cross_to_ray_edge_one);
	if (data->v < 0.0 || data->u + data->v > 1.0)
		return (false);
	return (true);
}

bool	calculate_determinant(t_ray ray, t_triangle_hit *data)
{
	double	determinant;

	data->cross_to_ray_edge_two = vec_cross(ray.direction,
			data->edge_two);
	determinant = vec_dot(data->edge_one, data->cross_to_ray_edge_two);
	if (fabs(determinant) < EPSILON)
		return (false);
	data->inverse_determinant = 1.0 / determinant;
	return (true);
}


bool	triangle_hit(t_object *object, t_ray ray,
			t_interval interval, t_hit_record *record)
{
	t_triangle_hit	data;

	data.edge_one = point_sub_point(object->data.triangle.point_b,
			object->data.triangle.point_a);
	data.edge_two = point_sub_point(object->data.triangle.point_c,
			object->data.triangle.point_a);
	data.to_ray = point_sub_point(ray.origin,
			object->data.triangle.point_a);
	if (!calculate_determinant(ray, &data))
		return (false);
	if (!calculate_coordinates(ray, &data))
		return (false);
	data.t = data.inverse_determinant* vec_dot(data.edge_two,
		data.cross_to_ray_edge_one);
	if (data.t <= interval.min || data.t >= interval.max)
		return (false);
	record->t = data.t;
	record->point = ray_at(ray, data.t);
	hit_record_set_face_normal(record, ray,
		 vec_normalize(vec_cross(data.edge_one,data.edge_two)));
	record->object = object;
	return (true);
}


//! steps:
/*
	1) Compute the triangle edges and the vector from vertex A to the ray:
		edge_one = B - A, edge_two = C - A, to_ray = O - A.
	2) Compute the determinant:
		cross_to_ray_edge_two = d x edge_two.
		determinant = edge_one . (d x edge_two).
	3) Reject a ray parallel to the triangle when:
		|determinant| < EPSILON.
		inverse_determinant = 1 / determinant.
	4) Compute the first barycentric coordinate:
		u = (to_ray . (d x edge_two)) / determinant.
		Reject when u < 0 or u > 1.
	5) Compute the second barycentric coordinate:
		cross_to_ray_edge_one = to_ray x edge_one.
		v = (d . (to_ray x edge_one)) / determinant.
		Reject when v < 0 or u + v > 1.
	6) Compute the ray parameter:
		t = (edge_two . (to_ray x edge_one)) / determinant.
		Reject when t <= interval.min or t >= interval.max.
	7) Compute the normalized triangle normal:
		outward_normal = normalize(edge_one x edge_two).
	8) Compute P = O + t*d, orient the normal, and store the object.
*/
