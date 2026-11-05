/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:41:30 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/29 16:46:58 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_record.h"

bool	world_hit(t_scene *scene, t_ray ray, t_interval interval,
		t_hit_record *record)
{
	t_object		*current;
	t_hit_record	temp;
	bool			hit_any;

	hit_any = false;
	current = scene->objects;
	while (current)
	{
		if (object_hit(current, ray, interval, &temp))
		{
			if (temp.t < interval.max)
			{
				interval.max = temp.t;
				*record = temp;
				hit_any = true;
			}
		}
		current = current->next;
	}
	return (hit_any);
}

//! steps:
/*
	1) Start with hit_any = false and current interval (min, max).
	2) Test P(t) = O + t*d against every object through object_hit.
	3) For a candidate hit with parameter t_hit, accept it only if:
		t_hit < interval.max.
	4) Keep the closest hit by updating:
		interval.max = t_hit,	record = candidate.
	5) Continue through every object; the decreasing max removes farther hits.
	6) Return hit_any, which is true exactly when a valid minimum t was found.
*/
