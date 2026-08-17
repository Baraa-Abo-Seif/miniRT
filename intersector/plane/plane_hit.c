#include "plane_hit.h"
#include <math.h>

bool	plane_hit(
t_plane *plane,t_ray ray,
t_interval interval,t_hit_record *record)
{
    double	denominator;
	double	t;
    t_vec	plane_to_ray;
    t_vec	outward_normal;

    denominator = vec_dot(ray.direction, plane->normal);
    if (fabs(denominator) < EPSILON)
        return (false);
   plane_to_ray = point_sub_point(plane->point, ray.origin); 
   t = vec_dot(plane_to_ray, plane->normal) / denominator;  
    if (t <= interval.min || t >= interval.max)
        return (false);
    record->t = t;
    record->point = ray_at(ray, t);
    outward_normal = plane->normal;
    hit_record_set_face_normal(record,ray,outward_normal);
    record->object = plane;
	return (true);
}

