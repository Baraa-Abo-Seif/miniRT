#include "closest_hit.h"
#include "object_dispatch.h"

bool	scene_closest_hit(t_scene *scene, t_ray ray,
			t_interval interval, t_hit_record *record)
{
	t_object	*current;
	t_hit_record	temp;
	bool		hit_any;

	hit_any = false;
	current = scene->objects;
	while (current)
	{
		if (object_hit(current, ray, interval, &temp))
		{
			interval.max = temp.t;
			*record = temp;
			hit_any = true;
		}
		current = current->next;
	}
	return (hit_any);
}
