#ifndef CYLINDER_HIT_H
# define CYLINDER_HIT_H

# include "../../scene/objects/cylinder/cylinder.h"
# include "../../scene/ray/ray.h"
# include "../hit/hit_record.h"
# include "../hit/interval.h"

typedef struct s_cyl_quad
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;
}	t_cyl_quad;

void	get_cap_data(t_cylinder *cyl, int side,
			t_point *cap_center, t_vec *cap_normal);
bool	check_one_cap(t_cylinder *cyl, t_ray ray,
			t_interval interval, int side);
bool	check_caps(t_cylinder *cyl, t_ray ray,
			t_interval interval, t_hit_record *record);
void	compute_body_eq(t_cylinder *cyl, t_ray ray, t_cyl_quad *eq);
bool	root_in_bounds(t_cylinder *cyl, t_ray ray,
			double t, t_interval interval);
bool	find_body_root(t_cylinder *cyl, t_ray ray,
			t_cyl_quad *eq, t_interval interval);
void	fill_body_record(t_cylinder *cyl, t_ray ray,
			t_cyl_quad *eq, t_hit_record *record);
bool	cylinder_hit(t_cylinder *cyl, t_ray ray,
			t_interval interval, t_hit_record *record);
			

#endif
