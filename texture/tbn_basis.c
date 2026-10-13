

#include "texture.h"

t_tbn	plane_tbn(t_vec normal)
{
	t_tbn	tbn;
	t_vec	reference;

	tbn.normal = vec_normalize(normal);
	if (fabs(tbn.normal.z) < 0.9)
		reference = (t_vec){0.0, 0.0, 1.0};
	else
		reference = (t_vec){0.0, 1.0, 0.0};
	tbn.tangent = vec_normalize(vec_cross(tbn.normal, reference));
	tbn.bitangent = vec_normalize(vec_cross(tbn.normal, tbn.tangent));
	return (tbn);
}

t_tbn	sphere_tbn(t_vec normal)
{
	t_tbn	tbn;
	t_vec	up;

	tbn.normal = vec_normalize(normal);
	if (fabs(tbn.normal.y) > 0.999)
		up = (t_vec){0.0, 0.0, 1.0};
	else
		up = (t_vec){0.0, 1.0, 0.0};
	tbn.tangent = vec_normalize(vec_cross(up, tbn.normal));
	tbn.bitangent = vec_normalize(vec_cross(tbn.normal, tbn.tangent));
	return (tbn);
}

t_tbn	cylinder_tbn(t_vec axis, t_vec normal)
{
	t_tbn	tbn;

	tbn.normal = vec_normalize(normal);
	tbn.tangent = vec_normalize(axis);
	tbn.bitangent = vec_normalize(vec_cross(tbn.tangent, tbn.normal));
	return (tbn);
}

t_tbn	triangle_tbn(t_point a, t_point b, t_vec normal)
{
	t_tbn	tbn;

	tbn.normal = vec_normalize(normal);
	tbn.tangent = vec_normalize(point_sub_point(b, a));
	tbn.bitangent = vec_normalize(vec_cross(tbn.normal, tbn.tangent));
	return (tbn);
}

t_tbn	paraboloid_tbn(t_vec axis, t_vec normal)
{
	t_tbn	tbn;
	t_vec	t;

	tbn.normal = vec_normalize(normal);
	t = vec_cross(axis, tbn.normal);
	if (vec_length(t) < EPSILON)
		return (plane_tbn(tbn.normal));
	tbn.tangent = vec_normalize(t);
	tbn.bitangent = vec_normalize(vec_cross(tbn.normal, tbn.tangent));
	return (tbn);
}
