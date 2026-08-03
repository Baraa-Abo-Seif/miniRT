#include "builder_internal.h"

bool	build_scene(t_token *tokens, t_scene *scene)
{
    t_token	*current;

    current = tokens;
    while (current)
    {
        if (current->type == TOKEN_AMBIENT && !build_ambient(scene, current))
            return (false);
        if (current->type == TOKEN_CAMERA && !build_camera(scene, current))
            return (false);
        if (current->type == TOKEN_LIGHT && !build_light(scene, current))
            return (false);
        if (!build_object(scene, current))
            return (false);
        current = current->next;
    }
    return (true);
}
