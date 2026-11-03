#ifndef RENDERER_H
#define RENDERER_H

#include "../scene/scene.h"
#include "../intersector/intersector.h"
#include "../lib_math/lib_math.h"
#include "../mlx_engine/mlx_api.h"
#include "../texture/texture.h"
#include "./camera/renderer_camera.h"



t_color	render_ambient(t_color object_color, t_ambient ambient);
bool	is_in_shadow(t_hit_record *record, t_scene *scene, t_light *light);
t_color	render_diffuse(t_color object_color,t_hit_record *record,
    t_scene *scene,t_light *light);
t_color	ray_color(t_ray ray, t_scene *scene);

t_color	shade_with_lights(t_object *object,
		t_hit_record *record, t_scene *scene, t_color base_color);
t_color	get_checker_color(t_object *object, t_point local_p);
t_point	pattern_point(t_object *object, t_point point);
t_uv	get_object_uv(t_object *object, t_point point);
t_color	shade_hit(t_hit_record *record, t_scene *scene);

t_color	render_specular(t_object *object,t_hit_record *record,
			t_scene *scene,t_light *light);



void	render(t_scene *scene, t_image *image);

int	run_renderer(t_scene *scene);






#endif