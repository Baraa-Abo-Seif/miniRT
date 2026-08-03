#include "builder_internal.h"

bool	build_ambient(t_scene *scene, t_token *token)
{
    scene->ambient.ratio = ft_atof(token->args[0]);
    scene->ambient.color = parse_color(token->args[1]);
    return (true);
}
