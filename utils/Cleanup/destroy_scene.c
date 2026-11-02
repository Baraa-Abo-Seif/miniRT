#include "cleanup.h"

void	destroy_scene(t_scene *scene)
{
    if (!scene)
        return ;
    destroy_light_list(scene->lights);
    destroy_object_list(scene->objects);
    free(scene);
}