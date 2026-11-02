#ifndef TEXTURE_DATA_H
# define TEXTURE_DATA_H

# include <stdbool.h>
# include "../lib_math/lib_math.h"

typedef struct s_uv
{
	double	u;
	double	v;
} t_uv;

typedef struct s_tbn
{
	t_vec	tangent;
	t_vec	bitangent;
	t_vec	normal;
} t_tbn;

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
} t_texture;

typedef struct s_bump_map
{
	bool		is_active;
	char		*filepath;
	double	intensity;
	t_texture	texture;
} t_bump_map;

typedef struct s_color_texture
{
	bool		is_active;
	char		*filepath;
	t_texture	texture;
} t_color_texture;

#endif
