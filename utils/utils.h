/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhoura <ralhoura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:51:18 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/05 18:08:26 by ralhoura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../scene/scene.h"
# include <stdbool.h>
# include <stddef.h>

void	destroy_object_list(t_object *objects);
void	destroy_light_list(t_light *lights);
void	destroy_scene(t_scene *scene);

void	destroy_bump_maps(void *mlx_ptr, t_scene *scene);
void	bump_map_destroy(void *mlx_ptr, t_bump_map *bump);
void	texture_destroy(void *mlx_ptr, t_texture *tex);
void	destroy_color_textures(void *mlx_ptr, t_scene *scene);
void	color_texture_destroy(void *mlx_ptr, t_color_texture *texture);

bool	error_msg(char *msg);
bool	error_msg_line(size_t line, char *msg);

#endif
