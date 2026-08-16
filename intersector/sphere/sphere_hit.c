#include "sphere_hit.h"
#include <stdio.h>


bool	sphere_hit(t_sphere *sphere,t_ray ray,
    t_interval interval,t_hit_record *record)
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;

	(void)interval;
	(void)record;

	oc = point_sub_point(ray.origin, sphere->center);
	a = vec_dot(ray.direction, ray.direction);
	b = 2.0 * vec_dot(oc, ray.direction);
	c = vec_dot(oc, oc) - (sphere->radius * sphere->radius);

    // for test :
    printf("a = %f\n", a);
    printf("b = %f\n", b);
    printf("c = %f\n", c);

	return (false);
}

//! steps:
/*
    1) Compute oc = ray.origin - sphere.center
        oc = o - c
    2) Compute a = dot(ray.direction, ray.direction)
        a = d . d
    3) Compute b = 2 * dot(oc, ray.direction)
        b = 2 * (oc . d)
    4) Compute c = dot(oc, oc) - (sphere.radius * sphere.radius)
        c = (oc . oc) - r^2
    5) Compute discriminant = b^2 - 4ac
        discriminant = b^2 - 4ac
*/




