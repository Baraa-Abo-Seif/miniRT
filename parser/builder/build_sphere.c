#include "builder_internal.h"

bool	build_sphere(t_scene *scene, t_token *token)
{
    t_object	*object;

    object = create_object(SPHERE);
    if (!object)
        return (false);
    object->data.sphere.center = parse_point(token->args[0]);
    object->data.sphere.radius = ft_atof(token->args[1]) / 2.0;
    object->color = parse_color(token->args[2]);
    append_object(&scene->objects, object);
    return (true);
}
