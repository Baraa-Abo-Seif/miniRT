#include "renderer.h"

t_color	ray_color(t_ray ray, t_scene *scene)
{
	t_hit_record	record;
    t_interval	interval;

    interval.min = RAY_T_MIN;
    interval.max = INFINITY;

	if (world_hit(scene, ray, interval, &record))
		return (shade_hit(&record, scene));
	return ((t_color){0.0, 0.0, 0.0});
}

