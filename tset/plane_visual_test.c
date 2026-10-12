#include <math.h>

#include "scene/camera/camera.h"

#include "scene/ray/ray.h"

#include "scene/objects/plane/plane.h"

#include "intersector/plane/plane_hit.h"
#include "intersector/hit/interval.h"
#include "intersector/hit/hit_record.h"

#include "mlx_engine/mlx_api.h"

#define WIDTH 800
#define HEIGHT 600

int	main(void)
{
	t_window		*window;
	t_image			*image;

	t_camera		camera;
	t_plane			plane;
	t_interval		interval;
	t_hit_record	record;
	t_ray			ray;

	int	x;
	int	y;

	/* Window */
	window = mlx_window_create(WIDTH, HEIGHT, "Plane Test");
	if (!window)
		return (1);

	image = mlx_image_create(window->mlx, WIDTH, HEIGHT);
	if (!image)
		return (1);

	if (mlx_image_data(image) == -1)
		return (1);

	/* Camera */
	camera.position = (t_point){0.0, 0.0, 0.0};
	camera.forward = (t_vec){0.0, 0.0, -1.0};
	camera.fov = 90.0;

	camera_init(&camera, WIDTH, HEIGHT);

	/* Plane */
	plane.point = (t_point){0.0, -1.0, -3.0};
	plane.normal = (t_vec){0.0, 1.0, 0.0};

	/* Interval */
	interval.min = 0.001;
	interval.max = INFINITY;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = camera_generate_ray(&camera, x, y);

			if (plane_hit(&plane, ray, interval, &record))
				mlx_image_pixel_put(image, x, y, 0xFFFFFFFF);
			else
				mlx_image_pixel_put(image, x, y, 0x00000000);

			x++;
		}
		y++;
	}

	mlx_put_image_to_window(
		window->mlx,
		window->win,
		image->img,
		0,
		0);

	mlx_loop(window->mlx);

	mlx_image_destroy(image);
	mlx_window_destroy(window);

	return (0);
}

