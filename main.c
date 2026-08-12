#include "./scene/camera/camera.h"
#include <stdio.h>

//for test :
/*
 cc -Wall -Wextra -Werror main.c scene/camera/camera_create.c scene/camera/camera_destroy.c scene/camera/camera_init.c scene/camera/camera_build_basis.c scene/camera/camera_compute_viewport.c scene/camera/camera_compute_pixel_delta.c math/vector/vec_add.c math/vector/vec_sub.c math/vector/vec_scale.c math/vector/vec_dot.c math/vector/vec_cross.c math/vector/vec_length.c math/vector/vec_normalize.c math/vector/vec_distance.c math/vector/vec_reflect.c math/point/point_add_vec.c math/point/point_sub_vec.c math/point/point_sub_point.c -ILibft -Iscene/camera -Imath/vector -Imath/point -LLibft -lft -lm -o camera_test
 
*/

int	main(void)
{
	t_camera	*camera;

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

	printf("=== Camera ===\n");
	printf("Position      : %.3f %.3f %.3f\n",
		camera->position.x,
		camera->position.y,
		camera->position.z);

	printf("Forward       : %.3f %.3f %.3f\n",
		camera->forward.x,
		camera->forward.y,
		camera->forward.z);

	printf("Right         : %.3f %.3f %.3f\n",
		camera->right.x,
		camera->right.y,
		camera->right.z);

	printf("Up            : %.3f %.3f %.3f\n",
		camera->up.x,
		camera->up.y,
		camera->up.z);

	printf("Viewport      : %.6f x %.6f\n",
		camera->viewport_width,
		camera->viewport_height);

	printf("Upper Left    : %.6f %.6f %.6f\n",
		camera->viewport_upper_left.x,
		camera->viewport_upper_left.y,
		camera->viewport_upper_left.z);

	printf("Pixel Delta X : %.6f %.6f %.6f\n",
		camera->pixel_delta_x.x,
		camera->pixel_delta_x.y,
		camera->pixel_delta_x.z);

	printf("Pixel Delta Y : %.6f %.6f %.6f\n",
		camera->pixel_delta_y.x,
		camera->pixel_delta_y.y,
		camera->pixel_delta_y.z);

	camera_destroy(camera);
	return (0);
}

