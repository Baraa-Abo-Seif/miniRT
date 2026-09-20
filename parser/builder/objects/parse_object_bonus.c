#include "object_builder.h"

void	parse_object_bonus(t_object *object,
			const t_token *token, size_t color_index)
{
	if (token->args[color_index + 1])
	{
		object->shininess = ft_atof(token->args[color_index + 1]);
		check_positive(object->shininess);
	}
}

