#include "builder_internal.h"

bool	build_plane(t_scene *scene, t_token *token)
{
    t_object	*object;

    object = create_object(PLANE);
    if (!object)
        return (false);
    object->data.plane.point = parse_point(token->args[0]);
    object->data.plane.normal = parse_vec(token->args[1]);
    object->color = parse_color(token->args[2]);
    append_object(&scene->objects, object);
    return (true);
}
