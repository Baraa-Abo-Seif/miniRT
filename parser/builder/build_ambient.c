#include "builder_internal.h"

t_ambient	build_ambient(const t_token *token)
{
    t_ambient	ambient;

    ambient.ratio = ft_atof(token->args[0]);
    ambient.color = parse_color(token->args[1]);
    return (ambient);
}

