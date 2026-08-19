#ifndef CLOSEST_HIT_H
# define CLOSEST_HIT_H

# include "../scene/scene.h"
# include "hit/hit_record.h"
# include "hit/interval.h"

bool	scene_closest_hit(t_scene *scene, t_ray ray,
			t_interval interval, t_hit_record *record);

#endif
