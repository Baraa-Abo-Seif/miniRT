#include "builder_internal.h"




t_scene	*create_scene(void)
{
    t_scene	*scene;

    scene = malloc(sizeof(t_scene));
    if (!scene)
        return (NULL);
    ft_bzero(scene, sizeof(t_scene));
    return (scene);
}


void	append_light(t_scene *scene, t_light *light)
{
    t_light	*current;

    if (!scene || !light)
        return ;
    if (!scene->lights)
    {
        scene->lights = light;
        return ;
    }
    current = scene->lights;
    while (current->next)
        current = current->next;
    current->next = light;
}
void	append_object(t_scene *scene, t_object *object)
{
    t_object	*current;

    if (!scene || !object)
        return ;
    if (!scene->objects)
    {
        scene->objects = object;
        return ;
    }
    current = scene->objects;
    while (current->next)
        current = current->next;
    current->next = object;
}


bool	add_light_to_scene(t_scene *scene, const t_token *token)
{
    t_light	*light;

    if (!scene || !token)
        return (false);
    light = build_light(token);
    if (!light)
    {
        destroy_scene(scene);
        return (false);
    }
    append_light(scene, light);
    return (true);
}



bool	add_object_to_scene(t_scene *scene, const t_token *token)
{
    t_object	*object;

    if (!scene || !token)
        return (false);
    object = build_object(token);
    if (!object)
    {
        destroy_scene(scene);
        return (false);
    }
    append_object(scene, object);
    return (true);
}