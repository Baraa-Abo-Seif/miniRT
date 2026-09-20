
#include "../builder_internal.h"

t_object	*build_sphere(const t_token *token)
{
	t_object	*object;

	object = create_object();
	if (!object)
		return (NULL);
	object->type = SPHERE;
	object->data.sphere.center = parse_point(token->args[0]);

	object->data.sphere.radius = ft_atof(token->args[1]);
	check_positive(object->data.sphere.radius);
	object->data.sphere.radius /= 2.0;

	object->color = parse_color(token->args[2]);
	parse_object_bonus(object, token, 2);

	return (object);
}



