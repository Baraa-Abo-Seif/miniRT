#include "cylinder_hit.h"
#include <math.h>

void	compute_body_eq(t_cylinder *cyl, t_ray ray, t_cyl_quad *eq)
{
	t_vec	oc;
	t_vec	w;
	t_vec	u;

	oc = point_sub_point(ray.origin, cyl->center);
	w = vec_sub(oc, vec_scale(cyl->axis, vec_dot(oc, cyl->axis)));
	u = vec_sub(ray.direction,
			vec_scale(cyl->axis, vec_dot(ray.direction, cyl->axis)));
	eq->a = vec_dot(u, u);
	eq->b = 2.0 * vec_dot(w, u);
	eq->c = vec_dot(w, w) - cyl->radius * cyl->radius;
	eq->discriminant = eq->b * eq->b - 4.0 * eq->a * eq->c;
}

bool	root_in_bounds(t_cylinder *cyl, t_ray ray,
			double t, t_interval interval)
{
	t_point	hit;
	t_vec	proj;

	if (t <= interval.min || t >= interval.max)
		return (false);
	hit = ray_at(ray, t);
	proj = point_sub_point(hit, cyl->center);
	if (fabs(vec_dot(proj, cyl->axis)) > cyl->height / 2.0 + EPSILON)
		return (false);
	return (true);
}

bool	find_body_root(t_cylinder *cyl, t_ray ray,
			t_cyl_quad *eq, t_interval interval)
{
	if (eq->a < EPSILON || eq->discriminant < 0.0)
		return (false);
	eq->sqrtd = sqrt(eq->discriminant);
	eq->root = (-eq->b - eq->sqrtd) / (2.0 * eq->a);
	if (root_in_bounds(cyl, ray, eq->root, interval))
		return (true);
	eq->root = (-eq->b + eq->sqrtd) / (2.0 * eq->a);
	if (root_in_bounds(cyl, ray, eq->root, interval))
		return (true);
	return (false);
}

void	fill_body_record(t_cylinder *cyl, t_ray ray,
			t_cyl_quad *eq, t_hit_record *record)
{
	t_vec	proj;
	t_point	center_proj;
	t_vec	outward_normal;

	record->t = eq->root;
	record->point = ray_at(ray, eq->root);
	proj = point_sub_point(record->point, cyl->center);
	center_proj = point_add_vec(cyl->center,
			vec_scale(cyl->axis, vec_dot(proj, cyl->axis)));
	outward_normal = vec_scale(
			point_sub_point(record->point, center_proj),
			1.0 / cyl->radius);
	hit_record_set_face_normal(record, ray, outward_normal);
	record->object = cyl;
}

bool	cylinder_hit(t_cylinder *cyl, t_ray ray,
			t_interval interval, t_hit_record *record)
{
	t_cyl_quad		eq;
	t_hit_record	temp;
	t_interval		tight;

	tight = interval;
	compute_body_eq(cyl, ray, &eq);
	if (find_body_root(cyl, ray, &eq, tight))
	{
		fill_body_record(cyl, ray, &eq, record);
		tight.max = record->t;
	}
	if (check_caps(cyl, ray, tight, &temp))
		*record = temp;
	return (record->t < interval.max);
}
