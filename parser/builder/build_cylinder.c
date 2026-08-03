#include "builder_internal.h"

bool	build_cylinder(t_scene *scene, t_token *token)
{
    t_object	*object;

    object = create_object(CYLINDER);
    if (!object)
        return (false);
    object->data.cylinder.center = parse_point(token->args[0]);
    object->data.cylinder.axis = parse_vec(token->args[1]);
    object->data.cylinder.radius = ft_atof(token->args[2]) / 2.0;
    object->data.cylinder.height = ft_atof(token->args[3]);
    object->color = parse_color(token->args[4]);
    append_object(&scene->objects, object);
    return (true);
}
