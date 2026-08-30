#include "sphere_hit.h"
#include "../../scene/objects/object.h"

void	calculate_equation(t_sphere *sphere,t_ray ray,t_quadratic_data *eq)
{
	t_vec	oc;

	oc = point_sub_point(ray.origin, sphere->center);
	eq->a = vec_dot(ray.direction, ray.direction);
	eq->b = 2.0 * vec_dot(oc, ray.direction);
	eq->c = vec_dot(oc, oc) - (sphere->radius * sphere->radius);
	eq->discriminant = (eq->b * eq->b) - (4.0 * eq->a * eq->c);
}

bool	find_root(t_quadratic_data *eq,t_interval interval)
{
	if (eq->discriminant < 0.0)
		return (false);
	eq->sqrtd = sqrt(eq->discriminant);
	eq->root = (-eq->b - eq->sqrtd) / (2.0 * eq->a);
	if (eq->root <= interval.min || eq->root >= interval.max)
	{
		eq->root = (-eq->b + eq->sqrtd) / (2.0 * eq->a);
		if (eq->root <= interval.min || eq->root >= interval.max)
			return (false);
	}
	return (true);
}



void fill_body_record_sphere(
    t_object *object,
    t_ray ray,
    t_quadratic_data *eq,
    t_hit_record *record)
{
	t_vec	outward_normal;

	record->t = eq->root;
	record->point = ray_at(ray, eq->root);
	outward_normal = vec_scale(
		point_sub_point(record->point, object->data.sphere.center),
		1.0 / object->data.sphere.radius);
	hit_record_set_face_normal(record, ray, outward_normal);
	
}

bool	sphere_hit(t_object *object, t_ray ray, t_interval interval, t_hit_record *record)
{
	t_quadratic_data	eq;
	t_sphere			*sphere;

	sphere = &object->data.sphere;
	record->object = object;
	calculate_equation(sphere, ray, &eq);

	if (!find_root(&eq, interval))
		return (false);
	fill_body_record_sphere(object, ray, &eq, record);
	return (true);
}


//! steps:
/*
    1) Compute oc = ray.origin - sphere.center
        oc = o - c
    2) Compute a = dot(ray.direction, ray.direction)
        a = d . d
    3) Compute b = 2 * dot(oc, ray.direction)
        b = 2 * (oc . d)
    4) Compute c = dot(oc, oc) - (sphere.radius * sphere.radius)
        c = (oc . oc) - r^2
    5) Compute discriminant = b^2 - 4ac
        discriminant = b^2 - 4ac

        Compute a,b,c
            │
            ▼
        Compute Δ
            │
             ▼
        Is Δ < 0 ?
            │
     ┌──────┴──────┐
     │             │
    Yes           No
     │             │
     ▼             ▼
    Return      Compute sqrt
    false

    note : The discriminant is computed first because it determines whether real roots exist. Only if Δ >= 0 does it make sense to compute sqrt(Δ) and continue solving for the intersection.


*/




