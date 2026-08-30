#include "builder_internal.h"

t_camera	build_camera(const t_token *token)
{
	t_camera	camera;

	ft_bzero(&camera, sizeof(camera));

	camera.position = parse_point(token->args[0]);
	camera.forward = parse_vector(token->args[1]);
	check_normal(camera.forward);

	camera.fov = ft_atof(token->args[2]);
	check_fov(camera.fov);

	return (camera);
}

