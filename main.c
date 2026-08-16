#include <stdio.h>

#include "./scene/camera/camera.h"
#include "./scene/objects/sphere/sphere.h"
#include "./intersector/sphere/sphere_hit.h"
#include "./intersector/hit/interval.h"
#include "./intersector/hit/hit_record.h"

int	main(void)
{
	t_camera		*camera;
	t_ray			ray;
	t_sphere		sphere;
	t_interval		interval;
	t_hit_record	record;

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

	sphere.center = (t_point){0.0, 0.0, -1.0};
	sphere.radius = 0.5;

	interval.min = 0.001;
	interval.max = 1000.0;

	ray = camera_generate_ray(camera, 400, 300);

	printf("=== Testing sphere_hit() ===\n\n");

	sphere_hit(&sphere, ray, interval, &record);

	camera_destroy(camera);

	return (0);
}

