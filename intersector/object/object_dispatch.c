#include "object_dispatch.h"


bool	object_hit(t_object *object, t_ray ray,
			t_interval interval, t_hit_record *record)
{
	if (!object)
		return (false);
	if (object->type == SPHERE)
		return (sphere_hit(&object->data.sphere, ray, interval, record));
	if (object->type == PLANE)
		return (plane_hit(&object->data.plane, ray, interval, record));
	if (object->type == CYLINDER)
		return (cylinder_hit(&object->data.cylinder, ray,
				interval, record));
	return (false);
}
