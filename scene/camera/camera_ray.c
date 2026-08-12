
#include "camera.h"
//Pixel=viewport_upper_left+(i+0.5)×pixel_deltax​+(j+0.5)×pixel_deltay
t_ray	camera_ray_through_pixel(t_camera *camera, int j, int i)
{
	t_point	pixel_center;
	t_vec	direction;

	if (!camera)
		return (ray_create((t_point){0.0, 0.0, 0.0}, (t_vec){0.0, 0.0, -1.0}));

	pixel_center = camera->viewport_upper_left;
	pixel_center = point_add_vec(
		pixel_center,
		vec_scale(camera->pixel_delta_x, j + 0.5));
	pixel_center = point_add_vec(
		pixel_center,
		vec_scale(camera->pixel_delta_y, i + 0.5));

	direction = vec_normalize(
			point_sub_point(pixel_center, camera->position));

	return (ray_create(camera->position, direction));
}
