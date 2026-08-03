#include "builder_internal.h"

bool	build_camera(t_scene *scene, t_token *token)
{
    scene->camera.position = parse_point(token->args[0]);
    scene->camera.forward = parse_vec(token->args[1]);
    scene->camera.fov = ft_atof(token->args[2]);
    return (true);
}
