#ifndef RENDERER_H
#define RENDERER_H

#include "../scene/scene.h"
#include "../intersector/intersector.h"
#include "../math/math.h"


t_color	render_ambient(t_color object_color, t_ambient ambient);
t_color	render_diffuse(t_color object_color,t_hit_record *record,t_scene *scene,t_light *light);
t_color	shade_hit(t_hit_record *record, t_scene *scene);

bool	is_in_shadow(t_hit_record *record,t_scene *scene,t_light *light);

#endif