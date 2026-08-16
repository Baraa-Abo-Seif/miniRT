#include <stdio.h>

#include "scene/camera/camera.h"
#include "scene/ray/ray.h"
#include "scene/objects/sphere/sphere.h"
#include "intersector/sphere/sphere_hit.h"
#include "intersector/hit/interval.h"

int	main(void)
{
	t_camera		*camera;
	t_ray			ray;
	t_sphere		sphere;
	t_hit_record	record;
	t_interval		interval;
	bool			hit;

	camera = camera_create();
	if (!camera)
		return (1);

	camera_init(camera, 800, 600);

	ray = camera_generate_ray(camera, 400, 300);

	sphere.center = (t_point){0.0, 0.0, -1.0};
	sphere.radius = 0.5;

	interval.min = 0.001;
	interval.max = 1000.0;

	hit = sphere_hit(&sphere, ray, interval, &record);

	printf("Hit: %s\n", hit ? "YES" : "NO");

	if (hit)
	{
		printf("t = %f\n", record.t);

		printf("Point = (%f, %f, %f)\n",
			record.point.x,
			record.point.y,
			record.point.z);

		printf("Normal = (%f, %f, %f)\n",
			record.normal.x,
			record.normal.y,
			record.normal.z);

		printf("Front Face = %s\n",
			record.front_face ? "true" : "false");

		printf("Object Pointer = %p\n", record.object);
	}

	camera_destroy(camera);

	return (0);
}


