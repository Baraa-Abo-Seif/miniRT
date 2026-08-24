#include "renderer.h"


bool	is_in_shadow(t_hit_record *record, t_scene *scene, t_light *light)
{
	t_point			shadow_origin;
	t_vec			shadow_direction;
	double			light_distance;
	t_ray			shadow_ray;
	t_hit_record	shadow_hit;
	t_interval		interval;

	shadow_origin = point_add_vec(
		record->point,
		vec_scale(record->normal, SHADOW_EPSILON));
	shadow_direction = point_sub_point(light->position, shadow_origin);
	light_distance = vec_length(shadow_direction);
	shadow_direction = vec_normalize(shadow_direction);
	shadow_ray = ray_create(shadow_origin, shadow_direction);
	interval.min = SHADOW_EPSILON;
	interval.max = light_distance - SHADOW_EPSILON;

	if (world_hit(scene, shadow_ray, interval, &shadow_hit))
		return (true);
	return (false);
}
