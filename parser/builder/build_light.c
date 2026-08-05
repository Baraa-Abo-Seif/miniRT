
#include "builder_internal.h"


t_light	*build_light(const t_token *token)
{
    t_light	*light;

    light = malloc(sizeof(t_light));
    if (!light)
        return (NULL);
    ft_bzero(light, sizeof(t_light));
    light->position = parse_point(token->args[0]);
    light->brightness = ft_atof(token->args[1]);
    light->color = parse_color(token->args[2]);
    return (light);
}
