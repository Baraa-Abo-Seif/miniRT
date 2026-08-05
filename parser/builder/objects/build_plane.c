
#include "object_builder.h"

t_object	*build_plane(const t_token *token)
{
    t_object	*object;

    object = create_object();
    if (!object)
        return (NULL);
    object->type = PLANE;
    object->data.plane.point = parse_point(token->args[0]);
    object->data.plane.normal = parse_vector(token->args[1]);
    object->color = parse_color(token->args[2]);
    return (object);
}
