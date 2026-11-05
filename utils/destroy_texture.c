/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhoura <ralhoura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:16:03 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/05 15:25:14 by ralhoura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	destroy_bump_maps(void *mlx_ptr, t_scene *scene)
{
	t_object	*object;

	if (!scene)
		return ;
	object = scene->objects;
	while (object)
	{
		bump_map_destroy(mlx_ptr, &object->bump_map);
		object = object->next;
	}
}

void	bump_map_destroy(void *mlx_ptr, t_bump_map *bump)
{
	if (!bump)
		return ;
	if (bump->filepath)
	{
		free(bump->filepath);
		bump->filepath = NULL;
	}
	texture_destroy(mlx_ptr, &bump->texture);
	bump->is_active = false;
}

void	texture_destroy(void *mlx_ptr, t_texture *tex)
{
	if (!tex)
		return ;
	if (tex->img_ptr && mlx_ptr)
		mlx_destroy_image(mlx_ptr, tex->img_ptr);
	tex->img_ptr = NULL;
	tex->addr = NULL;
	tex->width = 0;
	tex->height = 0;
	tex->is_loaded = false;
}

void	destroy_color_textures(void *mlx_ptr, t_scene *scene)
{
	t_object	*object;

	if (!scene)
		return ;
	object = scene->objects;
	while (object)
	{
		color_texture_destroy(mlx_ptr, &object->color_texture);
		object = object->next;
	}
}

void	color_texture_destroy(void *mlx_ptr, t_color_texture *texture)
{
	if (!texture)
		return ;
	if (texture->filepath)
	{
		free(texture->filepath);
		texture->filepath = NULL;
	}
	texture_destroy(mlx_ptr, &texture->texture);
	texture->is_active = false;
}
