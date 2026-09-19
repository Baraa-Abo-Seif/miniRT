#include "triangle_hit.h"

void	init_triangle_data(t_object *object, t_ray ray,
				t_triangle_hit *data)
{
	data->edge_one = point_sub_point(object->data.triangle.point_b,
			object->data.triangle.point_a);
	data->edge_two = point_sub_point(object->data.triangle.point_c,
			object->data.triangle.point_a);
	data->to_ray = point_sub_point(ray.origin,
			object->data.triangle.point_a);
}

bool	calculate_determinant(t_ray ray,
				t_triangle_hit *data)
{
	double	determinant;

	data->cross_to_ray_edge_two = vec_cross(ray.direction,
			data->edge_two);
	determinant = vec_dot(data->edge_one,
			data->cross_to_ray_edge_two);
	if (fabs(determinant) < EPSILON)
		return (false);
	data->inverse_determinant = 1.0 / determinant;
	return (true);
}

bool	calculate_coordinates(t_ray ray,
				t_triangle_hit *data)
{
	data->u = data->inverse_determinant
		* vec_dot(data->to_ray,
			data->cross_to_ray_edge_two);
	if (data->u < 0.0 || data->u > 1.0)
		return (false);
	data->cross_to_ray_edge_one = vec_cross(data->to_ray,
			data->edge_one);
	data->v = data->inverse_determinant
		* vec_dot(ray.direction,
			data->cross_to_ray_edge_one);
	if (data->v < 0.0 || data->u + data->v > 1.0)
		return (false);
	return (true);
}

bool	calculate_t(t_vec edge_two,
				t_triangle_hit *data,
				t_interval interval)
{
	data->t = data->inverse_determinant
		* vec_dot(edge_two,
			data->cross_to_ray_edge_one);
	if (data->t <= interval.min || data->t >= interval.max)
		return (false);
	return (true);
}

void	set_hit_record(t_object *object, t_ray ray,
				t_triangle_hit *data, t_hit_record *record)
{
	t_vec	outward_normal;

	outward_normal = vec_normalize(vec_cross(data->edge_one,
				data->edge_two));
	record->t = data->t;
	record->point = ray_at(ray, data->t);
	hit_record_set_face_normal(record, ray, outward_normal);
	record->object = object;
}

bool	triangle_hit(t_object *object, t_ray ray,
			t_interval interval, t_hit_record *record)
{
	t_triangle_hit	data;

	init_triangle_data(object, ray, &data);
	if (!calculate_determinant(ray, &data))
		return (false);
	if (!calculate_coordinates(ray, &data))
		return (false);
	if (!calculate_t(data.edge_two, &data, interval))
		return (false);
	set_hit_record(object, ray, &data, record);
	return (true);
}
