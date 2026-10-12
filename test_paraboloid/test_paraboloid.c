
#include <stdio.h>
#include <math.h>
#include "../math/math.h"

#include "../intersector/paraboloid/paraboloid_hit.h"

static int	g_failures;

static void	check_hit(const char *name, t_object *object,
		t_ray ray, t_interval interval, bool expected)
{
	t_hit_record	record;
	bool			result;

	result = paraboloid_hit(object, ray, interval, &record);
	if (result == expected)
	{
		printf("[PASS] %s\n", name);
		if (result)
			printf("       t = %.6f, point = (%.6f, %.6f, %.6f)\n",
				record.t, record.point.x, record.point.y,
				record.point.z);
	}
	else
	{
		printf("[FAIL] %s: expected %d, got %d\n",
			name, expected, result);
		g_failures++;
	}
}




static void	check_normal(const char *name, t_object *object,
		t_point point, t_vec expected)
{
	t_vec	normal;
	double	dot;

	normal = paraboloid_normal(&object->data.paraboloid,
			point, object->data.paraboloid.radius
			* object->data.paraboloid.radius
			/ (2.0 * object->data.paraboloid.height));
	dot = vec_dot(normal, expected);
	if (dot > 0.999)
		printf("[PASS] %s\n", name);
	else
	{
		printf("[FAIL] %s: dot = %.6f\n", name, dot);
		g_failures++;
	}
}


int	main(void)
{
	t_object	object;
	t_interval	interval;
	t_ray		ray;

	object = (t_object){0};
	object.type = PARABOLOID;
	object.data.paraboloid.vertex = (t_point){0, 0, 0};
	object.data.paraboloid.axis = (t_vec){0, 0, 1};
	object.data.paraboloid.radius = 2.0;
	object.data.paraboloid.height = 4.0;
	interval = (t_interval){0.001, INFINITY};




    ray = ray_create((t_point){0, 0, -1},
            (t_vec){0, 0, 1});
    check_hit("Axis-parallel ray", &object, ray, interval, true);

	ray = ray_create((t_point){0.5, 0, 2},
			(t_vec){1, 0, 0});
	check_hit("Ray crossing paraboloid", &object, ray,
		interval, true);

	ray = ray_create((t_point){3, 0, 2},
			(t_vec){0, 1, 0});
	check_hit("Ray outside paraboloid", &object, ray,
		interval, false);

    
	ray = ray_create((t_point){3, 0, 2},
			(t_vec){-1, 0, 0});
	check_hit("Choose nearest valid root", &object, ray,
		interval, true);

	ray = ray_create((t_point){3, 0, 5},
			(t_vec){-1, 0, 0});
	check_hit("Reject hit above height", &object, ray,
		interval, false);

	check_normal("Normal at vertex", &object,
		(t_point){0, 0, 0}, (t_vec){0, 0, -1});

    check_normal("Normal on curved surface", &object,
        (t_point){1.0, 0.0, 1.0}, (t_vec){1.0, 0.0, -0.5});
    
	ray = ray_create((t_point){1.0, -2.0, 1.0},
			(t_vec){0, 1, 0});
	check_hit("Tangent ray", &object, ray,
		interval, true);

	ray = ray_create((t_point){3.0, 0, 4.0},
			(t_vec){-1, 0, 0});
	check_hit("Hit at height boundary", &object, ray,
		interval, true);

	ray = ray_create((t_point){3.0, 0, 4.5},
			(t_vec){-1, 0, 0});
	check_hit("Reject hit beyond height", &object, ray,
		interval, false);

    	ray = ray_create((t_point){3.0, 0, 2.0},
			(t_vec){1, 0, 0});
	check_hit("Reject hit behind ray", &object, ray,
		interval, false);


	printf("\nFailures: %d\n", g_failures);
	return (g_failures != 0);
}

