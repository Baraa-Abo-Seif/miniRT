#include "./builder.h"

bool	build_ambient(const t_token *token, t_ambient *ambient)
{
	ambient->ratio = ft_atof(token->args[0]);
	check_positive(ambient->ratio);
	if (!check_ratio(ambient->ratio))
		return (false);
	return (parse_color(token->args[1], &ambient->color));
}



