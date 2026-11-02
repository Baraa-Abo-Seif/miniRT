
#ifndef TEXTURE_H
# define TEXTURE_H

# include "../scene/texture_data.h"
# include "../mlx/mlx.h"
# include "../scene/scene.h"
# include "../intersector/hit/hit_record.h"

typedef struct s_object t_object;
typedef struct s_scene t_scene;
typedef struct s_hit_record t_hit_record;


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



t_uv	uv_range(t_uv uv,int only_v);


void	compute_cylinder_tbn_uv(const t_object *obj,
		t_hit_record *rec, t_tbn *tbn, t_uv *uv);
void	compute_triangle_tbn_uv(const t_object *obj,
		t_hit_record *rec, t_tbn *tbn, t_uv *uv);
void	compute_paraboloid_tbn_uv(const t_object *obj,
		t_hit_record *rec, t_tbn *tbn, t_uv *uv);
void	compute_sphere_tbn_uv(const t_object *obj,
		t_hit_record *rec, t_tbn *tbn, t_uv *uv);
void	compute_plane_tbn_uv(const t_object *obj,
		t_hit_record *rec, t_tbn *tbn, t_uv *uv);
		
#endif
