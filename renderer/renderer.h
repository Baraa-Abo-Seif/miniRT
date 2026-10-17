#ifndef RENDERER_H
#define RENDERER_H

#include "../scene/scene.h"
#include "../intersector/intersector.h"
#include "../lib_math/lib_math.h"
#include "../mlx_engine/mlx_api.h"



void	render(t_scene *scene, t_image *image);

t_color	render_ambient(t_color object_color, t_ambient ambient);
t_color	render_diffuse(t_color object_color,t_hit_record *record,t_scene *scene,t_light *light);
t_color	shade_hit(t_hit_record *record, t_scene *scene);

bool	is_in_shadow(t_hit_record *record,t_scene *scene,t_light *light);
t_color	ray_color(t_ray ray, t_scene *scene);
int	run_renderer(t_scene *scene);

t_color	render_specular(t_object *object,
			t_hit_record *record,
			t_scene *scene,
			t_light *light);


void	camera_build_basis(t_camera *camera);
void	camera_compute_pixel_delta(t_camera *camera, int image_width, int image_height);

void		camera_compute_viewport(
t_camera *camera,int image_width,int image_height);
int	camera_init(t_camera *camera,int image_width,int image_height);
t_ray	camera_generate_ray(t_camera *camera, int x, int y);



#endif