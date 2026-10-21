#include "./builder.h"

bool	build_camera(const t_token *token, t_camera *camera)
{
	ft_bzero(camera, sizeof(*camera));

	camera->position = parse_point(token->args[0]);
	camera->forward = parse_vector(token->args[1]);
	if (!check_normal(camera->forward))
		return (false);

	camera->fov = ft_atof(token->args[2]);
	if (camera->fov < 0.0 || camera->fov > 180.0)
	{
		error_msg("FOV must be between 0.0 and 180.0");
		return (false);
	}
	return (true);
}

