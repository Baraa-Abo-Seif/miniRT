#include "camera.h"

void	camera_compute_pixel_delta(t_camera *camera, int image_width, int image_height)
{
	if (!camera)
		return ;

    camera->pixel_delta_x = vec_scale(
        camera->right,
        camera->viewport_width / (double)image_width);
        
    camera->pixel_delta_y = vec_scale(
        camera->up,
        -camera->viewport_height / (double)image_height);

}