#ifndef CLEANUP_H
#define CLEANUP_H

#include "../../scene/scene.h"
#include "../../texture/texture.h"


void	destroy_light_list(t_light *lights);
void	destroy_object_list(t_object *objects);
void	destroy_scene(t_scene *scene);

#endif
