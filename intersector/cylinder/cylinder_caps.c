#include "cylinder_hit.h"
#include <math.h>

void	get_cap_data(t_cylinder *cyl, int side,
			t_point *cap_center, t_vec *cap_normal)
{
	*cap_normal = vec_scale(cyl->axis, side);
	*cap_center = point_add_vec(cyl->center,
			vec_scale(cyl->axis, side * cyl->height / 2.0));
}

bool	check_one_cap(t_cylinder *cyl, t_ray ray,
			t_interval interval, int side)
{
	t_point	cap_center;
	t_point	hit_point;
	t_vec	cap_normal;
	t_vec	offset;
	t_vec	proj;
	double	denom;
	double	t;

	get_cap_data(cyl, side, &cap_center, &cap_normal);
	denom = vec_dot(ray.direction, cap_normal);
	if (fabs(denom) < EPSILON)
		return (false);
	t = vec_dot(point_sub_point(cap_center, ray.origin),
			cap_normal) / denom;
	if (t <= interval.min || t >= interval.max)
		return (false);
	hit_point = ray_at(ray, t);
	offset = point_sub_point(hit_point, cyl->center);
	proj = vec_scale(cyl->axis, vec_dot(offset, cyl->axis));
	if (vec_dot(offset, offset) - vec_dot(proj, proj)
		> cyl->radius * cyl->radius + EPSILON)
		return (false);
	return (true);
}
bool	check_caps(t_cylinder *cyl, t_ray ray,
			t_interval interval, t_hit_record *record)
{
	t_hit_record	temp;
	int				side;
	double			t;

	side = -1;
	while (side <= 1)
	{
		if (check_one_cap(cyl, ray, interval, side))
		{
			get_cap_data(cyl, side, &temp.point, &temp.normal);
			t = vec_dot(point_sub_point(temp.point, ray.origin),
					temp.normal);
			temp.t = t;
			temp.point = ray_at(ray, t);
			hit_record_set_face_normal(&temp, ray, temp.normal);
			temp.object = cyl;
			if (temp.t < record->t)
			{
				*record = temp;
				interval.max = temp.t;
			}
		}
		side += 2;
	}
	return (record->t < interval.max);
}
