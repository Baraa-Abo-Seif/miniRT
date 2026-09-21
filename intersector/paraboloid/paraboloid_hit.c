# include "paraboloid_hit.h"

void	make_basis(t_vec axis, t_vec *side, t_vec *other_side)
{
	t_vec	reference;

	if (fabs(axis.x) < 0.9)
		reference = (t_vec){1.0, 0.0, 0.0};
	else
		reference = (t_vec){0.0, 1.0, 0.0};
	*side = vec_normalize(vec_cross(axis, reference));
	*other_side = vec_cross(axis, *side);
}

t_vec	to_local(t_vec value, t_vec axis,
		t_vec side, t_vec other_side)
{
	return ((t_vec){vec_dot(value, side), vec_dot(value, other_side),
		vec_dot(value, axis)});
}

bool	valid_root(t_paraboloid *paraboloid, t_ray ray,
		t_interval interval, double root)
{
	t_vec	from_vertex;
	double	axis_distance;

	if (root <= interval.min || root >= interval.max)
		return (false);
	from_vertex = point_sub_point(ray_at(ray, root), paraboloid->vertex);
	axis_distance = vec_dot(from_vertex, paraboloid->axis);
	return (axis_distance >= 0.0 && axis_distance <= paraboloid->height);
}

bool	build_quadratic(t_paraboloid *paraboloid,
		t_ray ray, double coefficient, t_quadratic_data *equation)
{
	t_vec	side;
	t_vec	other_side;
	t_vec	origin;
	t_vec	direction;

	make_basis(paraboloid->axis, &side, &other_side);
	origin = to_local(point_sub_point(ray.origin, paraboloid->vertex),
			paraboloid->axis, side, other_side);
	direction = to_local(ray.direction,
			paraboloid->axis, side, other_side);
	equation->a = direction.x * direction.x
		+ direction.y * direction.y;
	equation->b = 2.0 * (origin.x * direction.x
			+ origin.y * direction.y)
		- 2.0 * coefficient * direction.z;
	equation->c = origin.x * origin.x
		+ origin.y * origin.y
		- 2.0 * coefficient * origin.z;
	equation->discriminant = equation->b * equation->b
		- 4.0 * equation->a * equation->c;
	if (fabs(equation->a) < EPSILON
		|| equation->discriminant < 0.0)
		return (false);
	return (true);
}

bool	paraboloid_find_root(t_paraboloid *paraboloid,
		t_ray ray, t_interval interval, double *root)
{
	t_quadratic_data	equation;
	double			coefficient;

	coefficient = paraboloid->radius * paraboloid->radius
		/ (2.0 * paraboloid->height);
	if (!build_quadratic(paraboloid, ray,
			coefficient, &equation))
		return (false);
	equation.sqrtd = sqrt(equation.discriminant);
	equation.root = (-equation.b - equation.sqrtd)
		/ (2.0 * equation.a);
	if (valid_root(paraboloid, ray, interval,
			equation.root))
	{
		*root = equation.root;
		return (true);
	}
	equation.root = (-equation.b + equation.sqrtd)
		/ (2.0 * equation.a);
	if (!valid_root(paraboloid, ray, interval, equation.root))
		return (false);
	*root = equation.root;
	return (true);
}

t_vec	paraboloid_normal(t_paraboloid *paraboloid, t_point point,
		double coefficient)
{
	t_vec	from_vertex;
	double	axis_distance;
	t_vec	axis_point;

	from_vertex = point_sub_point(point, paraboloid->vertex);
	axis_distance = vec_dot(from_vertex, paraboloid->axis);
	axis_point = vec_scale(paraboloid->axis, axis_distance);
	return (vec_normalize(vec_sub(vec_sub(from_vertex, axis_point),
		vec_scale(paraboloid->axis, coefficient))));
}

bool	paraboloid_hit(t_object *object, t_ray ray,
		t_interval interval, t_hit_record *record)
{
	t_paraboloid	*paraboloid;
	double		coefficient;
	double		root;

	paraboloid = &object->data.paraboloid;
	coefficient = paraboloid->radius * paraboloid->radius
		/ (2.0 * paraboloid->height);
	if (!paraboloid_find_root(paraboloid, ray, interval, &root))
		return (false);
	record->t = root;
	record->point = ray_at(ray, root);
	record->normal = paraboloid_normal(paraboloid, record->point,
		coefficient);
	hit_record_set_face_normal(record, ray, record->normal);
	record->object = object;
	return (true);
}
