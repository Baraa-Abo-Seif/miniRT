
#include "ray.h"
//new_point = origin + direction * t;

t_point	ray_at(t_ray ray, double t)
{
	return (point_add_vec(ray.origin, vec_scale(ray.direction, t)));
}
