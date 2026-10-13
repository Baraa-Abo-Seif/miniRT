
#include "texture.h"

static double	clamp_unit(double val)
{
	if (val < -1.0)
		return (-1.0);
	if (val > 1.0)
		return (1.0);
	return (val);
}

static void	cylinder_radial_basis(t_vec axis, t_vec *radial_x,
				t_vec *radial_z)
{
	t_vec	reference;

	if (fabs(axis.x) < 0.9)
		reference = (t_vec){1.0, 0.0, 0.0};
	else
		reference = (t_vec){0.0, 1.0, 0.0};
	*radial_x = vec_normalize(vec_cross(axis, reference));
	*radial_z = vec_normalize(vec_cross(axis, *radial_x));
}

t_uv	sphere_uv(t_point point, t_point center, double radius)
{
	t_vec	d;
	t_uv	uv;
	double	phi;
	double	theta;

	d = point_sub_point(point, center);
	if (radius > EPSILON)
		d = vec_scale(d, 1.0 / radius);
	theta = atan2(d.x, d.z);
	uv.u = (theta + M_PI) / (2.0 * M_PI);
	phi = acos(clamp_unit(d.y));
	uv.v = phi / M_PI;
	return (uv);
}

t_uv	plane_uv(t_point point, t_point plane_pt, t_vec normal)
{
	t_tbn	tbn;
	t_vec	d;
	t_uv	uv;
	double	u_raw;
	double	v_raw;

	tbn = plane_tbn(normal);
	d = point_sub_point(point, plane_pt);
	u_raw = vec_dot(d, tbn.tangent) * BUMP_PLANE_SCALE;
	v_raw = vec_dot(d, tbn.bitangent) * BUMP_PLANE_SCALE;
	uv.u = u_raw - floor(u_raw);
	uv.v = v_raw - floor(v_raw);
	return (uv);
}
static t_uv	uv_range(t_uv uv)
{
	if (uv.u < 0.0)
		uv.u = 0.0;
	if (uv.u > 1.0)
		uv.u = 1.0;
	if (uv.v < 0.0)
		uv.v = 0.0;
	if (uv.v > 1.0)
		uv.v = 1.0;
	return (uv);
}

t_uv	cylinder_uv(t_point point, t_point center, t_vec axis, double height)
{
	t_vec	d;
	t_vec	radial;
	t_vec	radial_x;
	t_vec	radial_z;
	double	axial;
	double	angle;
	t_uv	uv;

	d = point_sub_point(point, center);
	axial = vec_dot(d, axis);
	radial = vec_sub(d, vec_scale(axis, axial));
	cylinder_radial_basis(axis, &radial_x, &radial_z);
	angle = (atan2(vec_dot(radial, radial_x),
				vec_dot(radial, radial_z)) + M_PI)
		/ (2.0 * M_PI);
	uv.u = (axial + (height / 2.0)) / height;
	uv.v = angle;
	return (uv_range(uv));
}
t_uv	triangle_uv(t_point point, t_point a, t_point b, t_point c)
{
	t_vec	v0;
	t_vec	v1;
	t_vec	v2;
	double	dots[5];
	double	denom;
	t_uv	uv;

	v0 = point_sub_point(b, a);
	v1 = point_sub_point(c, a);
	v2 = point_sub_point(point, a);
	dots[0] = vec_dot(v0, v0);
	dots[1] = vec_dot(v0, v1);
	dots[2] = vec_dot(v1, v1);
	dots[3] = vec_dot(v2, v0);
	dots[4] = vec_dot(v2, v1);
	denom = dots[0] * dots[2] - dots[1] * dots[1];
	if (fabs(denom) < EPSILON)
		return ((t_uv){0.0, 0.0});
	uv.u = (dots[2] * dots[3] - dots[1] * dots[4]) / denom;
	uv.v = (dots[0] * dots[4] - dots[1] * dots[3]) / denom;
	return (uv_range(uv));
}

static void	paraboloid_radial_basis(t_vec axis, t_vec *rx, t_vec *rz)
{
	t_vec	ref;

	if (fabs(axis.x) < 0.9)
		ref = (t_vec){1.0, 0.0, 0.0};
	else
		ref = (t_vec){0.0, 1.0, 0.0};
	*rx = vec_normalize(vec_cross(axis, ref));
	*rz = vec_cross(axis, *rx);
}

t_uv	paraboloid_uv(t_point point, t_point vertex, t_vec axis, double height)
{
	t_vec	d;
	t_vec	rx;
	t_vec	rz;
	t_vec	radial;
	double	axial;
	t_uv	uv;

	d = point_sub_point(point, vertex);
	axial = vec_dot(d, axis);
	radial = vec_sub(d, vec_scale(axis, axial));
	paraboloid_radial_basis(axis, &rx, &rz);
	uv.u = (atan2(vec_dot(radial, rx), vec_dot(radial, rz)) + M_PI)
		/ (2.0 * M_PI);
	if (height > EPSILON)
		uv.v = axial / height;
	else
		uv.v = 0.0;
	if (uv.v < 0.0)
		uv.v = 0.0;
	if (uv.v > 1.0)
		uv.v = 1.0;
	return (uv);
}
