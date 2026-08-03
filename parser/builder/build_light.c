#include "builder_internal.h"

bool	build_light(t_scene *scene, t_token *token)
{
    t_light	*light;

    light = create_light();
    if (!light)
        return (false);
    light->position = parse_point(token->args[0]);
    light->brightness = ft_atof(token->args[1]);
    light->color = parse_color(token->args[2]);
    append_light(&scene->lights, light);
    return (true);
}
