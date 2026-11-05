/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:58:01 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/03 17:58:02 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

void	texture_color_at(const t_texture *tex, t_uv uv, t_color *color)
{
	int				x;
	int				y;
	int				offset;
	unsigned char	*pixel;

	if (!tex || !tex->is_loaded || !tex->addr || !color)
		return ;
	uv.u -= floor(uv.u);
	uv.v -= floor(uv.v);
	x = (int)(uv.u * (tex->width - 1));
	y = (int)(uv.v * (tex->height - 1));
	offset = y * tex->line_length + x * (tex->bits_per_pixel / 8);
	pixel = (unsigned char *)(tex->addr + offset);
	color->r = pixel[2] / 255.0;
	color->g = pixel[1] / 255.0;
	color->b = pixel[0] / 255.0;
}

int	load_bump_maps(void *mlx_ptr, t_scene *scene)
{
	t_object	*object;

	if (!mlx_ptr || !scene)
		return (-1);
	object = scene->objects;
	while (object)
	{
		if (object->bump_map.is_active && texture_load_xpm(mlx_ptr,
				object->bump_map.filepath, &object->bump_map.texture))
		{
			error_msg("miniRT: failed to load bump map");
			return (-1);
		}
		object = object->next;
	}
	return (0);
}

int	texture_load_xpm(void *mlx_ptr, const char *filepath, t_texture *tex)
{
	if (!mlx_ptr || !filepath || !tex)
		return (-1);
	tex->img_ptr = mlx_xpm_file_to_image(mlx_ptr, (char *)filepath, &tex->width,
			&tex->height);
	if (!tex->img_ptr)
		return (-1);
	tex->addr = mlx_get_data_addr(tex->img_ptr, &tex->bits_per_pixel,
			&tex->line_length, &tex->endian);
	if (!tex->addr)
	{
		mlx_destroy_image(mlx_ptr, tex->img_ptr);
		tex->img_ptr = NULL;
		return (-1);
	}
	tex->is_loaded = true;
	return (0);
}

int	load_color_textures(void *mlx_ptr, t_scene *scene)
{
	t_object	*object;

	if (!mlx_ptr || !scene)
		return (-1);
	object = scene->objects;
	while (object)
	{
		if (object->color_texture.is_active && texture_load_xpm(mlx_ptr,
				object->color_texture.filepath, &object->color_texture.texture))
		{
			error_msg("miniRT: failed to load color texture");
			return (-1);
		}
		object = object->next;
	}
	return (0);
}
