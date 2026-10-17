#ifndef PLANE_HIT_H
# define PLANE_HIT_H

# include "../../lib_math/lib_math.h"
# include "../hit/hit_record.h"
# include "../hit/interval.h"
#include "../../scene/scene.h"
typedef struct s_plane_data
{
	double	denominator;
	double	t;
}	t_plane_data;

bool plane_hit(
    t_object *object,
    t_ray ray,
    t_interval interval,
    t_hit_record *record);

#endif


