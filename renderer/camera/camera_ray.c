/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 18:01:04 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/29 18:01:05 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer_camera.h"

t_ray	camera_generate_ray(t_camera *camera, int x, int y)
{
	t_point	pixel_center;
	t_vec	direction;
	t_ray	ray;

	pixel_center = camera->viewport_upper_left;
	pixel_center = point_add_vec(pixel_center, vec_scale(camera->pixel_delta_x,
				x + 0.5));
	pixel_center = point_add_vec(pixel_center, vec_scale(camera->pixel_delta_y,
				y + 0.5));
	direction = vec_normalize(point_sub_point(pixel_center, camera->position));
	ray.origin = camera->position;
	ray.direction = direction;
	return (ray);
}
// Pixel=viewport_upper_left+(i+0.5)×pixel_deltax​+(j+0.5)×pixel_deltay