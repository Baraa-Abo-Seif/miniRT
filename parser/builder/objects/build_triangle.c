#include "object_builder.h"

t_object	*build_triangle(const t_token *token)
{
	t_object	*object;

	object = create_object();
	if (!object)
		return (NULL);

	object->type = TRIANGLE;
	object->data.triangle.point_a = parse_point(token->args[0]);
	object->data.triangle.point_b = parse_point(token->args[1]);
	object->data.triangle.point_c = parse_point(token->args[2]);
	object->color = parse_color(token->args[3]);
	parse_object_bonus(object, token, 3);


	return (object);
}