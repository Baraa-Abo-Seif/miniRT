/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 18:22:49 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/29 18:22:50 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

t_color	ray_color(t_ray ray, t_scene *scene)
{
	t_hit_record	record;
	t_interval		interval;

	interval.min = RAY_T_MIN;
	interval.max = INFINITY;
	if (world_hit(scene, ray, interval, &record))
		return (shade_hit(&record, scene));
	return ((t_color){0.0, 0.0, 0.0});
}
