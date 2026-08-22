#include <stdio.h>

#include "intersector/cylinder/cylinder_hit.h"

int	main(void)
{
	t_cylinder		cylinder;
	t_ray			ray;
	t_interval		interval;
	t_hit_record	record;

	/* Cylinder */

	cylinder.center = (t_point){0.0, 0.0, 0.0};
	cylinder.axis = vec_normalize((t_vec){0.0, 1.0, 0.0});
	cylinder.radius = 1.0;
	cylinder.height = 2.0;

	/* Ray */

	ray.origin = (t_point){0.0, 0.0, -5.0};
	ray.direction = vec_normalize((t_vec){0.0, 0.0, 1.0});

	/* Interval */

	interval.min = 0.001;
	interval.max = 1e9;

	/* Test */

	if (cylinder_hit(&cylinder, ray, interval, &record))
	{
		printf("========== HIT ==========\n");

		printf("t = %f\n", record.t);

		printf(
			"Point : (%f, %f, %f)\n",
			record.point.x,
			record.point.y,
			record.point.z);

		printf(
			"Normal : (%f, %f, %f)\n",
			record.normal.x,
			record.normal.y,
			record.normal.z);

		printf("Front Face : %d\n", record.front_face);
	}
	else
	{
		printf("NO HIT\n");
	}

	return (0);
}