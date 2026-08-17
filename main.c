#include <stdio.h>
#include <math.h>

#include "scene/objects/plane/plane.h"
#include "scene/ray/ray.h"
#include "intersector/hit/hit_record.h"
#include "intersector/hit/interval.h"
#include "intersector/plane/plane_hit.h"

int	main(void)
{
	t_plane			plane;
	t_ray			ray;
	t_interval		interval;
	t_hit_record	record;

	/* Plane */
	plane.point = (t_point){0.0, 0.0, -1.0};
	plane.normal = (t_vec){0.0, 0.0, 1.0};

	/* Ray */
	ray.origin = (t_point){0.0, 0.0, 0.0};
	ray.direction = (t_vec){0.0, 0.0, -1.0};

	/* Interval */
	interval.min = 0.001;
	interval.max = INFINITY;

	if (plane_hit(&plane, ray, interval, &record))
	{
		printf("Hit: YES\n");
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
		printf("Object Pointer = %p\n",
			record.object);
	}
	else
	{
		printf("Hit: NO\n");
	}
	return (0);
}

