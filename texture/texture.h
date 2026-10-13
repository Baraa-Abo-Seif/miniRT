/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 11:36:00 by bablo             #+#    #+#             */
/*   Updated: 2026/10/12 18:05:48 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include <stdbool.h>
# include "../math/math.h"
# include "../intersector/hit/hit_record.h"

# define DEFAULT_BUMP_INTENSITY 1.0
# define BUMP_PLANE_SCALE 0.25

/* Forward declaration of object structure to prevent circular dependencies */
struct	s_object;
struct	s_scene;

/* UV Coordinates normalized to [0, 1] */
typedef struct s_uv
{
	double	u;
	double	v;
}	t_uv;

/* Orthonormal Tangent, Bitangent, Normal (TBN) coordinate frame */
typedef struct s_tbn
{
	t_vec	tangent;
	t_vec	bitangent;
	t_vec	normal;
}	t_tbn;

/* Image texture buffer representation */
typedef struct s_texture
{
	int		width;
	int		height;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img_ptr;
	bool	is_loaded;
}	t_texture;

/* Bump map metadata and image container */
typedef struct s_bump_map
{
	bool		is_active;
	char		*filepath;
	double		intensity;
	t_texture	texture;
}	t_bump_map;

typedef struct s_color_texture
{
	bool		is_active;
	char		*filepath;
	t_texture	texture;
}	t_color_texture;

t_uv	sphere_uv(t_point point, t_point center, double radius);
t_uv	plane_uv(t_point point, t_point plane_pt, t_vec normal);
t_uv	cylinder_uv(t_point point, t_point center, t_vec axis, double height);
t_uv	triangle_uv(t_point point, t_point a, t_point b, t_point c);
t_uv	paraboloid_uv(t_point point, t_point vertex, t_vec axis, double height);

t_tbn	sphere_tbn(t_vec normal);
t_tbn	plane_tbn(t_vec normal);
t_tbn	cylinder_tbn(t_vec axis, t_vec normal);
t_tbn	triangle_tbn(t_point a, t_point b, t_vec normal);
t_tbn	paraboloid_tbn(t_vec axis, t_vec normal);

double	bump_sample_height(const t_texture *tex, double u, double v);
t_vec	bump_perturb_normal(const t_bump_map *bump, t_tbn tbn, t_uv uv);
void	apply_bump_mapping(const struct s_object *object, t_hit_record *record);
void	texture_color_at(const t_texture *tex, t_uv uv, t_color *color);

int		texture_load_xpm(void *mlx_ptr, const char *filepath, t_texture *tex);
void	texture_destroy(void *mlx_ptr, t_texture *tex);
void	bump_map_destroy(void *mlx_ptr, t_bump_map *bump);
void	color_texture_destroy(void *mlx_ptr, t_color_texture *texture);
int		load_bump_maps(void *mlx_ptr, struct s_scene *scene);
void	destroy_bump_maps(void *mlx_ptr, struct s_scene *scene);
int		load_color_textures(void *mlx_ptr, struct s_scene *scene);
void	destroy_color_textures(void *mlx_ptr, struct s_scene *scene);

#endif
