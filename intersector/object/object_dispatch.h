#ifndef OBJECT_DISPATCH_H
# define OBJECT_DISPATCH_H

# include "../scene/objects/object.h"
# include "../scene/ray/ray.h"
# include "../hit/hit_record.h"
# include "../hit/interval.h"

#include "../sphere/sphere_hit.h"
#include "../plane/plane_hit.h"
#include "../cylinder/cylinder_hit.h"
#include "../triangle/triangle_hit.h"

bool	object_hit(t_object *object, t_ray ray,
			t_interval interval, t_hit_record *record);

#endif
