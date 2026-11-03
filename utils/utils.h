/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:51:18 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/03 23:21:42 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../mlx/mlx.h"
# include "../scene/scene.h"

# include <stdbool.h>
# include <stddef.h>
#include "../Libft/libft.h"

typedef struct s_light t_light;
typedef struct s_object t_object;
typedef struct s_scene t_scene;
typedef struct s_color_texture t_color_texture;
typedef struct s_bump_map t_bump_map;
typedef struct s_texture t_texture;

void	destroy_object_list(t_object *objects);
void	destroy_light_list(t_light *lights);
void	destroy_scene(t_scene *scene);

void	destroy_bump_maps(void *mlx_ptr, t_scene *scene);
void	bump_map_destroy(void *mlx_ptr, t_bump_map *bump);
void	texture_destroy(void *mlx_ptr, t_texture *tex);
void	destroy_color_textures(void *mlx_ptr, t_scene *scene);
void	color_texture_destroy(void *mlx_ptr, t_color_texture *texture);

bool	error_msg( char *msg);
bool	error_msg_line(size_t line,  char *msg);

#endif
