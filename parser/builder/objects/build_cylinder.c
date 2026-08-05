#include "object_builder.h"

t_object	*build_cylinder(const t_token *token)
{
	t_object	*object;

	object = create_object();
	if (!object)
		return (NULL);
	object->type = CYLINDER;
	object->data.cylinder.center = parse_point(token->args[0]);
	object->data.cylinder.axis = parse_vector(token->args[1]);
	object->data.cylinder.radius = ft_atof(token->args[2]) / 2.0;
	object->data.cylinder.height = ft_atof(token->args[3]);
	object->color = parse_color(token->args[4]);
	return (object);
}

