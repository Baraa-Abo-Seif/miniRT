/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_body.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 18:42:22 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/26 18:42:23 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder_hit.h"

void	fill_body_record(t_cylinder *cylinder,t_ray ray,
	t_quadratic_data *eq,t_hit_record *record)
{
	t_vec	center_to_hit;
	t_point	axis_point;
	t_vec	outward_normal;

	record->t = eq->root;
	record->point = ray_at(ray, eq->root);
	center_to_hit = point_sub_point(record->point,cylinder->center);
	axis_point = point_add_vec(cylinder->center,vec_scale(cylinder->axis,
		vec_dot(center_to_hit,cylinder->axis)));
	outward_normal = point_sub_point(record->point,axis_point);
	outward_normal = vec_scale(outward_normal,1.0 / cylinder->radius);
	hit_record_set_face_normal(record,ray,outward_normal);
	record->object = cylinder;
}

bool	is_valid_body_root(t_cylinder *cylinder,t_ray ray,
	double root,t_interval interval)
{
	t_point	hit_point;
	double	height;

	if (root <= interval.min || root >= interval.max)
		return (false);
	hit_point = ray_at(ray, root);
	height = vec_dot(point_sub_point(hit_point, cylinder->center),
	 cylinder->axis);
	if (fabs(height) > cylinder->height / 2.0)
		return (false);
	return (true);
}

bool	find_body_root(t_cylinder *cylinder,t_ray ray,
	t_quadratic_data *eq,t_interval interval)
{
	if (fabs(eq->a) < EPSILON || eq->discriminant < 0.0)
		return (false);
	eq->sqrtd = sqrt(eq->discriminant);
	eq->root = (-eq->b - eq->sqrtd) / (2.0 * eq->a);
	if (is_valid_body_root(cylinder, ray, eq->root, interval))
		return (true);
	eq->root = (-eq->b + eq->sqrtd) / (2.0 * eq->a);
	if (is_valid_body_root(cylinder, ray, eq->root, interval))
		return (true);
	return (false);
}

void	compute_body_eq(t_quadratic_data *eq, t_cylinder *cylinder,
	t_ray ray)
{
	t_vec	w;
	t_vec	m;
	t_vec	n;

	w = point_sub_point(ray.origin, cylinder->center);
	m = vec_sub(w, vec_scale(cylinder->axis, vec_dot(w, cylinder->axis)));
	n = vec_sub(ray.direction, vec_scale(cylinder->axis,
		 vec_dot(ray.direction, cylinder->axis)));
	eq->a = vec_dot(n, n);
	eq->b = 2.0 * vec_dot(m, n);
	eq->c = vec_dot(m, m) - cylinder->radius * cylinder->radius;
	eq->discriminant = eq->b * eq->b - 4.0 * eq->a * eq->c;
}

bool	cylinder_hit(t_object *object, t_ray ray, t_interval interval,
	t_hit_record *record)
{
	t_quadratic_data	eq;
	t_cap_context		ctx;
	bool	hit;

	hit = false;
	ctx.ray = ray;
	ctx.interval = interval;
	ctx.record = record;
	compute_body_eq(&eq, &object->data.cylinder, ray);
	if (find_body_root(&object->data.cylinder, ray, &eq, interval))
	{
		fill_body_record(&object->data.cylinder, ray, &eq, record);
    	hit = true;
    	ctx.interval.max = record->t;
	}
	if (check_caps(&object->data.cylinder, &ctx))
		hit = true;
	if (hit)
		record->object = object;
	return (hit);
}

//! steps:
/*
	Body equation:
	1) Let w = O - C, where C is the cylinder center.
	2) Remove the components parallel to the cylinder axis a:
		m = w - (w . a)a, n = d - (d . a)a.
	3) The infinite-cylinder equation is |m + t*n|^2 = r^2.
		Therefore:
		A = n . n,
		B = 2(m . n),
		C = m . m - r^2.
	4) Compute the discriminant:
		Delta = B^2 - 4AC.
		Reject when |A| < EPSILON or Delta < 0.
	5) Compute the two roots:
		t1 = (-B - sqrt(Delta)) / (2A),
		t2 = (-B + sqrt(Delta)) / (2A).
	6) For each root, compute H = (P(t) - C) . a and accept only when:
		interval.min < t < interval.max and |H| <= height / 2.
	7) For a body hit, project the point onto the axis:
		axis_point = C + ((P - C) . a)a,
		outward_normal = (P - axis_point) / r.

	Full cylinder:
	8) Try the body intersection and set interval.max = t_body when it hits.
	9) Check both caps using the reduced interval, keeping the closest hit.
	10) Store the cylinder as the hit object when body or cap intersection succeeds.
*/




