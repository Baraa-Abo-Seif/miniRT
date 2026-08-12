# include "camera.h"

t_camera	*camera_create(void)
{
	t_camera	*camera;

	camera = ft_calloc(1, sizeof(t_camera));
	if (!camera)
		return (NULL);

	/* Default camera looking toward -Z */
	camera->forward = (t_vec){0.0, 0.0, -1.0};
	camera->fov = 60.0;
	return (camera);
}




