#ifndef PARABOLOID_HIT_H
# define PARABOLOID_HIT_H

# include "../../scene/objects/paraboloid.h"
# include "../../scene/ray/ray.h"
# include "../hit/hit_record.h"
# include "../hit/interval.h"
# include "../../scene/objects/object.h"

bool	paraboloid_hit(t_object *object, t_ray ray,
		t_interval interval, t_hit_record *record);
void	make_basis(t_vec axis, t_vec *side, t_vec *other_side);
t_vec	to_local(t_vec value, t_vec axis,
		t_vec side, t_vec other_side);
bool	valid_root(t_paraboloid *paraboloid, t_ray ray,
		t_interval interval, double root);
bool	build_quadratic(t_paraboloid *paraboloid,
		t_ray ray, double coefficient, t_quadratic_data *equation);
bool	paraboloid_find_root(t_paraboloid *paraboloid,
		t_ray ray, t_interval interval, double *root);
t_vec	paraboloid_normal(t_paraboloid *paraboloid, t_point point,
		double coefficient);


#endif