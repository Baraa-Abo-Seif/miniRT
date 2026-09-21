# include "object_builder.h"

t_object	*build_paraboloid(const t_token *token)
{
	t_object	*object;
	double		diameter;

	object = create_object();
	if (!object)
		return (NULL);
	object->type = PARABOLOID;
	object->data.paraboloid.vertex = parse_point(token->args[0]);
	object->data.paraboloid.axis = parse_vector(token->args[1]);
	check_normal(object->data.paraboloid.axis);
	diameter = ft_atof(token->args[2]);
	check_positive(diameter);
	object->data.paraboloid.radius = diameter / 2.0;
	object->data.paraboloid.height = ft_atof(token->args[3]);
	check_positive(object->data.paraboloid.height);
	object->color = parse_color(token->args[4]);
	parse_object_bonus(object, token, 4);
	return (object);
}