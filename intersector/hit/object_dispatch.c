/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_dispatch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:29:01 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/29 17:20:07 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../intersector.h"

bool	object_hit(t_object *object, t_ray ray, t_interval interval,
		t_hit_record *record)
{
	if (!object)
		return (false);
	if (object->type == SPHERE)
		return (sphere_hit(object, ray, interval, record));
	if (object->type == PLANE)
		return (plane_hit(object, ray, interval, record));
	if (object->type == CYLINDER)
		return (cylinder_hit(object, ray, interval, record));
	if (object->type == TRIANGLE)
		return (triangle_hit(object, ray, interval, record));
	if (object->type == PARABOLOID)
		return (paraboloid_hit(object, ray, interval, record));
	return (false);
}

//! steps:
/*
	1) Reject a null object.
	2) Select the intersection function using the type mapping:
		SPHERE -> sphere_hit,	PLANE -> plane_hit,
		CYLINDER -> cylinder_hit,	TRIANGLE -> triangle_hit,
		PARABOLOID -> paraboloid_hit.
	3) Each selected function tests P(t) = O + t*d over the supplied interval.
	4) Return false when the type is unsupported.
*/
