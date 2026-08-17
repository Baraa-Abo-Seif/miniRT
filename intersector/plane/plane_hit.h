#ifndef PLANE_HIT_H
# define PLANE_HIT_H

# include "../../scene/objects/plane/plane.h"
# include "../../scene/ray/ray.h"
# include "../hit/hit_record.h"
# include "../hit/interval.h"

typedef struct s_plane_data
{
	double	denominator;
	double	t;
}	t_plane_data;

bool	plane_hit(
			t_plane *plane,
			t_ray ray,
			t_interval interval,
			t_hit_record *record);

#endif


