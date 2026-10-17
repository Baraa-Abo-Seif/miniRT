/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:42:39 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 14:42:54 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//new_point = origin + direction * t;
#include "ray.h"

t_point	ray_at(t_ray ray, double t)
{
	return (point_add_vec(ray.origin, vec_scale(ray.direction, t)));
}
