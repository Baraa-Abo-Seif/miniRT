#ifndef CYLINDER_HIT_H
# define CYLINDER_HIT_H

# include "../../scene/objects/cylinder/cylinder.h"
# include "../../scene/ray/ray.h"
# include "../hit/hit_record.h"
# include "../hit/interval.h"


typedef struct s_cap_context
{
	t_ray			ray;
	t_interval		interval;
	t_hit_record	*record;
}	t_cap_context;


bool	find_cap_root(
	t_cap_context *ctx,
	t_point cap_center,
	t_vec cap_normal,
	double *root);

bool	cylinder_hit(
	t_cylinder *cylinder,
	t_ray ray,
	t_interval interval,
	t_hit_record *record);

bool	find_body_root(
	t_cylinder *cylinder,t_ray ray,
	t_quadratic_data *eq,t_interval interval);

void	fill_body_record(
	t_cylinder *cylinder,t_ray ray,
	t_quadratic_data *eq,t_hit_record *record);

void	compute_body_eq( t_quadratic_data *eq,t_cylinder *cylinder,t_ray ray);

bool	is_valid_body_root(
	t_cylinder *cylinder,t_ray ray,
	double root,t_interval interval);

void	get_cap_data(t_cylinder *cylinder,int side,
	t_point *cap_center,t_vec *cap_normal);

bool	check_single_cap(
	t_cylinder *cylinder,int side,t_cap_context *ctx);


bool	check_caps(
	t_cylinder *cylinder,
	t_cap_context *ctx);

	
#endif



			


