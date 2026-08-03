#include "builder_internal.h"

bool	build_object(t_scene *scene, t_token *token)
{
    if (token->type == TOKEN_SPHERE)
        return (build_sphere(scene, token));
    if (token->type == TOKEN_PLANE)
        return (build_plane(scene, token));
    if (token->type == TOKEN_CYLINDER)
        return (build_cylinder(scene, token));
    return (true);
}
