#ifndef SPHERE_HIT_H
#define SPHERE_HIT_H

#include "../../scene/objects/sphere/sphere.h"
#include "../../scene/ray/ray.h"

#include "../hit/hit_record.h"
#include "../hit/interval.h"


bool	sphere_hit(
	t_sphere *sphere,
	t_ray ray,
	t_interval interval,
	t_hit_record *record);





#endif
