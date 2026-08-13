#include "./scene/camera/camera.h"
#include <stdio.h>

//for test :
/*
 cc -Wall -Wextra -Werror main.c scene/camera/camera_create.c scene/camera/camera_destroy.c scene/camera/camera_init.c scene/camera/camera_build_basis.c scene/camera/camera_compute_viewport.c scene/camera/camera_compute_pixel_delta.c scene/camera/camera_ray.c math/ray/ray_create.c math/ray/ray_at.c math/vector/vec_add.c math/vector/vec_sub.c math/vector/vec_scale.c math/vector/vec_dot.c math/vector/vec_cross.c math/vector/vec_length.c math/vector/vec_normalize.c math/vector/vec_distance.c math/vector/vec_reflect.c math/point/point_add_vec.c math/point/point_sub_vec.c math/point/point_sub_point.c -ILibft -Iscene/camera -Imath/vector -Imath/point -Imath/ray -LLibft -lft -lm -o ray_test

*/


#include "./mlx_engine/mlx_api.h"
#include <math.h>

static int	ray_direction_to_color(t_vec dir)
{
	int	r;
	int	g;
	int	b;

	r = (int)((dir.x + 1.0) * 127.5);
	g = (int)((dir.y + 1.0) * 127.5);
	b = (int)((-dir.z) * 255.0);

	if (r < 0)
		r = 0;
	if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	if (b > 255)
		b = 255;

	return ((r << 16) | (g << 8) | b);
}

static void	render_test(t_image *image, t_camera *camera)
{
	int		x;
	int		y;
	t_ray	ray;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			ray = camera_generate_ray(camera, x, y);
			mlx_image_pixel_put(
				image,
				x,
				y,
				ray_direction_to_color(ray.direction));
			x++;
		}
		y++;
	}
}



#define WIDTH 800
#define HEIGHT 600
int	main(void)
{
	t_window	*window;
	t_image		*image;
	t_camera	*camera;

	window = mlx_window_create(800, 600, "miniRT");
	if (!window)
		return (1);

	image = mlx_image_create(window->mlx, 800, 600);
	if (!image)
		return (1);

	if (mlx_image_data(image) != 0)
		return (1);

	camera = camera_create();
	if (!camera)
		return (1);

	camera->position = (t_point){0, 0, 0};
	camera->forward = (t_vec){0, 0, -1};
	camera->fov = 60.0;

	if (camera_init(camera, 800, 600))
		return (1);

	render_test(image, camera);

	mlx_display_image(window, image);

	mlx_event_init(window);

	mlx_event_loop(window);

	camera_destroy(camera);
	mlx_image_destroy(image);
	mlx_window_destroy(window);

	return (0);
}

