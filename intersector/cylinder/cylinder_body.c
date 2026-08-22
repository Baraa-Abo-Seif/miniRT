#include "cylinder_hit.h"
#include <math.h>


void	compute_body_eq(
	t_quadratic_data *eq,
	t_cylinder *cylinder,
	t_ray ray)
{
	t_vec	w;
	t_vec	m;
	t_vec	n;
	double	proj_w;
	t_vec	proj_vec_w;
	double	proj_d;
	t_vec	proj_vec_d;

	w = point_sub_point(ray.origin, cylinder->center);
	proj_w = vec_dot(w, cylinder->axis);
	proj_vec_w = vec_scale(cylinder->axis, proj_w);
	m = vec_sub(w, proj_vec_w);
	proj_d = vec_dot(ray.direction, cylinder->axis);
	proj_vec_d = vec_scale(cylinder->axis, proj_d);
	n = vec_sub(ray.direction, proj_vec_d);
	eq->a = vec_dot(n, n);
	eq->b = 2.0 * vec_dot(m, n);
	eq->c = vec_dot(m, m) - cylinder->radius * cylinder->radius;
	eq->discriminant = eq->b * eq->b - 4.0 * eq->a * eq->c;
}

bool	is_valid_body_root(
	t_cylinder *cylinder,t_ray ray,
	double root,t_interval interval)
{
	t_point	hit_point;
	t_vec	h;
	double	height;

	if (root <= interval.min || root >= interval.max)
		return (false);
	hit_point = ray_at(ray, root);
	h = point_sub_point(hit_point, cylinder->center);

	height = vec_dot(h, cylinder->axis);

	if (fabs(height) > cylinder->height / 2.0)
		return (false);

	return (true);
}

bool	find_body_root(
	t_cylinder *cylinder,t_ray ray,
	t_quadratic_data *eq,t_interval interval)
{
	if (eq->discriminant < 0.0)
		return (false);

	eq->sqrtd = sqrt(eq->discriminant);

	eq->root = (-eq->b - eq->sqrtd)
		/ (2.0 * eq->a);

	if (is_valid_body_root(cylinder, ray, eq->root, interval))
		return (true);

	eq->root = (-eq->b + eq->sqrtd)
		/ (2.0 * eq->a);

	if (is_valid_body_root(cylinder, ray, eq->root, interval))
		return (true);

	return (false);
}

void	fill_body_record(
	t_cylinder *cylinder,t_ray ray,
	t_quadratic_data *eq,t_hit_record *record)
{
	t_vec	center_to_hit;
	t_point	axis_point;
	t_vec	outward_normal;

	record->t = eq->root;
	record->point = ray_at(ray, eq->root);
	center_to_hit = point_sub_point(
		record->point,cylinder->center);
	axis_point = point_add_vec(
		cylinder->center,vec_scale(cylinder->axis,
			vec_dot(center_to_hit,cylinder->axis)));

	outward_normal = point_sub_point(
		record->point,axis_point);
	outward_normal = vec_scale(
		outward_normal,1.0 / cylinder->radius);
	hit_record_set_face_normal(record,ray,outward_normal);
	record->object = cylinder;
}


bool	cylinder_hit(
	t_cylinder *cylinder,
	t_ray ray,
	t_interval interval,
	t_hit_record *record)
{
	t_quadratic_data	eq;
	t_cap_context		ctx;
	bool	hit;

	hit = false;
	ctx.ray = ray;
	ctx.interval = interval;
	ctx.record = record;
	compute_body_eq(&eq, cylinder, ray);

	if (find_body_root(cylinder, ray, &eq, interval))
	{
		fill_body_record(cylinder,ray,&eq,record);
		ctx.interval.max = record->t;
		hit = true;
	}
	if (check_caps(cylinder, &ctx))
		hit = true;

	return (hit);
}





