#include "object_dispatch.h"


bool	object_hit(t_object *object, t_ray ray,
			t_interval interval, t_hit_record *record)
{
	if (!object)
		return (false);
	if (object->type == SPHERE)
		return (sphere_hit(object, ray, interval, record));
	if (object->type == PLANE)
		return (plane_hit(object, ray, interval, record));

	if (object->type == CYLINDER)
		return (cylinder_hit(object, ray, interval, record));
	if (object->type == TRIANGLE)
		return (triangle_hit(object, ray, interval, record));
	return (false);
}
