
#include "camera.h"
int	camera_init(
	t_camera *camera,
	int image_width,
	int image_height)
{
	if (!camera)
		return (1);

	camera_build_basis(camera);
	camera_compute_viewport(camera, image_width, image_height);
	camera_compute_pixel_delta(camera, image_width, image_height);

	return (0);
}





