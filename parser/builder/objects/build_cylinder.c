#include "object_builder.h"

t_object	*build_cylinder(const t_token *token)
{
	t_object	*object;
	double		diameter;
	double		height;

	object = create_object();
	if (!object)
		return (NULL);

	object->type = CYLINDER;
	object->data.cylinder.center = parse_point(token->args[0]);
	object->data.cylinder.axis = parse_vector(token->args[1]);
	check_normal(object->data.cylinder.axis);

	diameter = ft_atof(token->args[2]);
	check_positive(diameter);
	object->data.cylinder.radius = diameter / 2.0;

	height = ft_atof(token->args[3]);
	check_positive(height);
	object->data.cylinder.height = height;

	object->color = parse_color(token->args[4]);

	return (object);
}

