/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 18:01:13 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/26 18:01:14 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane_hit.h"


bool	plane_hit( t_object *object,t_ray ray,
    t_interval interval, t_hit_record *record)
{
    double	denominator;
	double	t;
    t_vec	plane_to_ray;
    t_vec	outward_normal;

    denominator = vec_dot(ray.direction, object->data.plane.normal);
    if (fabs(denominator) < EPSILON)
        return (false);
   plane_to_ray = point_sub_point(object->data.plane.point, ray.origin); 
   t = vec_dot(plane_to_ray, object->data.plane.normal) / denominator;  
    if (t <= interval.min || t >= interval.max)
        return (false);
    record->t = t;
    record->point = ray_at(ray, t);
    outward_normal = object->data.plane.normal;
    hit_record_set_face_normal(record,ray,outward_normal);
    record->object = object;
	return (true);
}

//! steps:
/*
    1) The ray is P(t) = O + t*d and the plane satisfies:
        (P - plane_point) . n = 0.
    2) Substitute the ray into the plane equation:
        (O + t*d - plane_point) . n = 0.
    3) Compute the denominator:
        denominator = d . n.
        If |denominator| < EPSILON, then d . n = 0 and the ray is parallel.
    4) Compute plane_to_ray = plane_point - O and solve for t:
        t = (plane_to_ray . n) / (d . n).
    5) Reject when t <= interval.min or t >= interval.max.
    6) Compute P = O + t*d, orient n against d, store the object, and return true.
*/

