
#include "ray.h"

t_ray	ray_create(t_point origin, t_vec direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}
