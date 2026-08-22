#include "cylinder_hit.h"
#include <math.h>



void	get_cap_data(
	t_cylinder *cylinder,int side,
	t_point *cap_center,t_vec *cap_normal)
{
	*cap_normal = vec_scale(cylinder->axis,side);

	*cap_center = point_add_vec(cylinder->center,
		vec_scale(cylinder->axis,side * (cylinder->height / 2.0)));


}

bool	find_cap_root(
t_cap_context *ctx,t_point cap_center,
t_vec cap_normal,double *root)
{
	double	denom;
	t_vec	center_to_origin;
	double	numerator;

	denom = vec_dot(ctx->ray.direction,cap_normal);
	if (fabs(denom) < EPSILON)
		return (false);
	center_to_origin = point_sub_point(
	cap_center,ctx->ray.origin);
	numerator = vec_dot(
		center_to_origin,cap_normal);
		*root = numerator / denom;

	if (*root <= ctx->interval.min || *root >= ctx->interval.max)
		return (false);

	return (true);
}


bool	check_single_cap(
	t_cylinder *cylinder,int side,t_cap_context *ctx)
{
	t_point	cap_center;
	t_vec	cap_normal;
	double	root;
	t_point	hit_point;
	t_vec	offset;

	get_cap_data(cylinder,side,&cap_center,&cap_normal);
	if (!find_cap_root(ctx,cap_center,cap_normal,&root))
		return (false);
	hit_point = ray_at(ctx->ray,root);
	offset = point_sub_point(hit_point,cap_center);
	if (vec_dot(offset, offset)
	> cylinder->radius * cylinder->radius)
		return (false);
	ctx->record->t = root;
	ctx->record->point = hit_point;
	hit_record_set_face_normal(ctx->record, ctx->ray, cap_normal);
	ctx->record->object = cylinder;
	return (true);
}
bool	check_caps(
	t_cylinder *cylinder,
	t_cap_context *ctx)
{
	int		side;
	bool	hit;

	side = -1;
	hit = false;
	while (side <= 1)
	{
		if (check_single_cap(cylinder, side, ctx))
		{
			hit = true;
			ctx->interval.max = ctx->record->t;
		}
		side += 2;
	}
	return (hit);
}



