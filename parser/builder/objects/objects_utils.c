#include "./object_builder.h"

t_object *failed_object (t_object *object)
{ 
    if (object)
    {
        bump_map_destroy(NULL, &object->bump_map);
        color_texture_destroy(NULL, &object->color_texture);
        free(object);
    }
	return (NULL);
}

void failled_massage(const char *msg, char **parts)
{
	if (msg)
		error_msg((char *)msg);
	free_string_array(parts);
}

void object_setup(t_object *object,const t_token *token)
{
	if (object->type == CYLINDER)
	{
		object->data.cylinder.center = parse_point(token->args[0]);
		object->data.cylinder.axis = parse_vector(token->args[1]);
	}
    else if (object->type == PARABOLOID)
    {
        object->data.paraboloid.vertex = parse_point(token->args[0]);
        object->data.paraboloid.axis = parse_vector(token->args[1]);
    }
    else if (object->type == PLANE)
    {
        object->data.plane.point = parse_point(token->args[0]);
        object->data.plane.normal = parse_vector(token->args[1]);
    }
    else if (object->type == SPHERE)
    {
        object->data.sphere.center = parse_point(token->args[0]);
        object->data.sphere.radius = ft_atof(token->args[1]);
    }
}

