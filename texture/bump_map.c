

#include "texture.h"
#include "../scene/objects/object.h"

double	bump_sample_height(const t_texture *tex, double u, double v)
{
	int				x;
	int				y;
	int				offset;
	unsigned char	*pixel;

	if (!tex || !tex->is_loaded || !tex->addr)
		return (0.0);
	u = u - floor(u);
	v = v - floor(v);
	x = (int)(u * (tex->width - 1));
	y = (int)(v * (tex->height - 1));
	if (x < 0)
		x = 0;
	if (x >= tex->width)
		x = tex->width - 1;
	if (y < 0)
		y = 0;
	if (y >= tex->height)
		y = tex->height - 1;
	offset = y * tex->line_length + x * (tex->bits_per_pixel / 8);
	pixel = (unsigned char *)(tex->addr + offset);
	return ((0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0]) / 255.0);
}

void	texture_color_at(const t_texture *tex, t_uv uv, t_color *color)
{
	int				x;
	int				y;
	int				offset;
	unsigned char	*pixel;

	if (!tex || !tex->is_loaded || !tex->addr || !color)
		return ;
	uv.u -= floor(uv.u);
	uv.v -= floor(uv.v);
	x = (int)(uv.u * (tex->width - 1));
	y = (int)(uv.v * (tex->height - 1));
	offset = y * tex->line_length + x * (tex->bits_per_pixel / 8);
	pixel = (unsigned char *)(tex->addr + offset);
	color->r = pixel[2] / 255.0;
	color->g = pixel[1] / 255.0;
	color->b = pixel[0] / 255.0;
}

t_vec	bump_perturb_normal(const t_bump_map *bump, t_tbn tbn, t_uv uv)
{
	double	delta_u;
	double	delta_v;
	double	grad_u;
	double	grad_v;
	t_vec	perturbed;

	delta_u = 1.0 / (double)bump->texture.width;
	delta_v = 1.0 / (double)bump->texture.height;
	grad_u = (bump_sample_height(&bump->texture, uv.u + delta_u, uv.v)
			- bump_sample_height(&bump->texture, uv.u - delta_u, uv.v));
	grad_v = (bump_sample_height(&bump->texture, uv.u, uv.v + delta_v)
			- bump_sample_height(&bump->texture, uv.u, uv.v - delta_v));
	perturbed = vec_sub(tbn.normal,
			vec_scale(tbn.tangent, grad_u * bump->intensity * 2.0));
	perturbed = vec_sub(perturbed,
			vec_scale(tbn.bitangent, grad_v * bump->intensity * 2.0));
	return (vec_normalize(perturbed));
}

static bool	compute_object_tbn_uv(const t_object *obj, t_hit_record *rec,
		t_tbn *tbn, t_uv *uv)
{
	if (obj->type == SPHERE)
	{
		*uv = sphere_uv(rec->point, obj->data.sphere.center,
				obj->data.sphere.radius);
		*tbn = sphere_tbn(rec->normal);
		return (true);
	}
	if (obj->type == PLANE)
	{
		*uv = plane_uv(rec->point, obj->data.plane.point, rec->normal);
		*tbn = plane_tbn(rec->normal);
		return (true);
	}
	if (obj->type == CYLINDER)
	{
		*uv = cylinder_uv(rec->point, obj->data.cylinder.center,
				obj->data.cylinder.axis, obj->data.cylinder.height);
		*tbn = cylinder_tbn(obj->data.cylinder.axis, rec->normal);
		return (true);
	}
	if (obj->type == TRIANGLE)
	{
		*uv = triangle_uv(rec->point, obj->data.triangle.point_a,
				obj->data.triangle.point_b, obj->data.triangle.point_c);
		*tbn = triangle_tbn(obj->data.triangle.point_a,
				obj->data.triangle.point_b, rec->normal);
		return (true);
	}
	if (obj->type == PARABOLOID)
	{
		*uv = paraboloid_uv(rec->point, obj->data.paraboloid.vertex,
				obj->data.paraboloid.axis, obj->data.paraboloid.height);
		*tbn = paraboloid_tbn(obj->data.paraboloid.axis, rec->normal);
		return (true);
	}
	return (false);
}

void	apply_bump_mapping(const t_object *object, t_hit_record *record)
{
	t_tbn	tbn;
	t_uv	uv;
	t_vec	perturbed;

	if (!object || !object->bump_map.is_active
		|| !object->bump_map.texture.is_loaded)
		return ;
	if (!compute_object_tbn_uv(object, record, &tbn, &uv))
		return ;
	perturbed = bump_perturb_normal(&object->bump_map, tbn, uv);
	record->normal = perturbed;
}
