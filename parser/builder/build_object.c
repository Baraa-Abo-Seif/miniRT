
#include "builder_internal.h"


t_object	*build_object(const t_token *token)
{
	if (token->type == TOKEN_SPHERE)
		return (build_sphere(token));
	if (token->type == TOKEN_PLANE)
		return (build_plane(token));
	if (token->type == TOKEN_CYLINDER)
		return (build_cylinder(token));
	if (token->type == TOKEN_TRIANGLE)
		return (build_triangle(token));
	if (token->type == TOKEN_PARABOLOID)
		return (build_paraboloid(token));
	return (NULL);
}








