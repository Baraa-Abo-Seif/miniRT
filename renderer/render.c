/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 18:56:25 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/03 18:56:26 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

void	render(t_scene *scene, t_image *image)
{
	int	x;
	int	y;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			mlx_image_pixel_put(image, x, y,
				color_to_hex(ray_color(camera_generate_ray(&scene->camera, x,
							y), scene)));
			x++;
		}
		y++;
	}
}
