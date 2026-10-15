
#include "renderer.h"


bool	is_in_shadow(t_hit_record *record, t_scene *scene, t_light *light)
{
	t_point			shadow_origin;
	t_vec			shadow_direction;
	double			light_distance;
	t_ray			shadow_ray;
	t_hit_record	shadow_hit;
	t_interval		interval;

	shadow_direction = point_sub_point(light->position, record->point);
	light_distance = vec_length(shadow_direction);
	shadow_direction = vec_normalize(shadow_direction);
	shadow_origin = point_add_vec(
		record->point,vec_scale(shadow_direction, SHADOW_EPSILON));
	shadow_ray.origin =shadow_origin;
	shadow_ray.direction =shadow_direction;
	interval.min = SHADOW_EPSILON;
	interval.max = light_distance - SHADOW_EPSILON;

	if (world_hit(scene, shadow_ray, interval, &shadow_hit))
		return (true);
	return (false);
}
