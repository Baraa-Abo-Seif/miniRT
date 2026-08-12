#include "./scene/camera/camera.h"
#include <stdio.h>

//for test :
/*
 cc -Wall -Wextra -Werror main.c scene/camera/camera_create.c scene/camera/camera_destroy.c scene/camera/camera_init.c scene/camera/camera_build_basis.c scene/camera/camera_compute_viewport.c scene/camera/camera_compute_pixel_delta.c scene/camera/camera_ray.c math/ray/ray_create.c math/ray/ray_at.c math/vector/vec_add.c math/vector/vec_sub.c math/vector/vec_scale.c math/vector/vec_dot.c math/vector/vec_cross.c math/vector/vec_length.c math/vector/vec_normalize.c math/vector/vec_distance.c math/vector/vec_reflect.c math/point/point_add_vec.c math/point/point_sub_vec.c math/point/point_sub_point.c -ILibft -Iscene/camera -Imath/vector -Imath/point -Imath/ray -LLibft -lft -lm -o ray_test

*/

int	main(void)
{
	t_camera	*camera;
	t_ray		ray;
	t_point		hit;
	int			j;
	int			i;

	camera = camera_create();
	if (!camera)
		return (1);

	camera->position = (t_point){0.0, 0.0, 0.0};
	camera->forward = (t_vec){0.0, 0.0, -1.0};
	camera->fov = 60.0;

	if (camera_init(camera, 800, 600) != 0)
	{
		camera_destroy(camera);
		return (1);
	}

	printf("=== Ray Generation ===\n");

	j = 400;
	i = 300;
	ray = camera_ray_through_pixel(camera, j, i);
	printf("Center pixel (400, 300):\n");
	printf("  origin    : %.3f %.3f %.3f\n",
		ray.origin.x, ray.origin.y, ray.origin.z);
	printf("  direction : %.3f %.3f %.3f\n",
		ray.direction.x, ray.direction.y, ray.direction.z);
	printf("  len       : %.6f\n", vec_length(ray.direction));

	hit = ray_at(ray, 1.0);
	printf("  P = O + 1*D : %.3f %.3f %.3f\n",
		hit.x, hit.y, hit.z);

	ray = camera_ray_through_pixel(camera, 0, 0);
	printf("Top-left pixel (0, 0):\n");
	printf("  direction : %.3f %.3f %.3f\n",
		ray.direction.x, ray.direction.y, ray.direction.z);

	ray = camera_ray_through_pixel(camera, 799, 599);
	printf("Bottom-right pixel (799, 599):\n");
	printf("  direction : %.3f %.3f %.3f\n",
		ray.direction.x, ray.direction.y, ray.direction.z);

	camera_destroy(camera);
	return (0);
}
