#include "object_builder.h"

void	parse_object_bonus(t_object *object,
			const t_token *token, size_t color_index)
{
	if (!token->args[color_index + 1])
		return ;
	if (ft_strncmp(token->args[color_index + 1], "checker", 8) == 0)
	{
		object->pattern.type = PATTERN_CHECKER;
		object->pattern.color_a = parse_color(token->args[color_index + 2]);
		object->pattern.color_b = parse_color(token->args[color_index + 3]);
		if (token->args[color_index + 4])
		{
			object->shininess = ft_atof(token->args[color_index + 4]);
			check_positive(object->shininess);
		}
		return ;
	}
	if (token->args[color_index + 1])
	{
		object->shininess = ft_atof(token->args[color_index + 1]);
		check_positive(object->shininess);
	}
}

