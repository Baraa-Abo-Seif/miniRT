/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_renderer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 18:57:30 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/03 19:12:03 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

t_image	*init_renderer_image(t_window *window)
{
	t_image	*image;

	image = mlx_image_create(window->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!image)
		return (NULL);
	if (mlx_image_data(image))
	{
		mlx_image_destroy(image);
		return (NULL);
	}
	return (image);
}

int	destroy_renderer(t_window *window, t_scene *scene)
{
	destroy_bump_maps(window->mlx, scene);
	destroy_color_textures(window->mlx, scene);
	mlx_window_destroy(window);
	return (-1);
}

int	load_scene_textures(t_window *window, t_scene *scene)
{
	if (load_bump_maps(window->mlx, scene))
		return (-1);
	if (load_color_textures(window->mlx, scene))
	{
		destroy_bump_maps(window->mlx, scene);
		return (-1);
	}
	return (0);
}

int	run_renderer(t_scene *scene)
{
	t_window	*window;
	t_image		*image;

	if (camera_init(&scene->camera, WINDOW_WIDTH, WINDOW_HEIGHT))
		return (-1);
	window = mlx_window_create(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	if (!window)
		return (-1);
	if (load_scene_textures(window, scene))
		return (destroy_renderer(window, scene));
	image = init_renderer_image(window);
	if (!image)
		return (destroy_renderer(window, scene));
	window->image = image;
	render(scene, image);
	mlx_display_image(window, image);
	mlx_event_init(window);
	mlx_event_loop(window);
	mlx_image_destroy(image);
	destroy_renderer(window, scene);
	return (0);
}
