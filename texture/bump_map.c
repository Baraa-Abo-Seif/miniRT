/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:11:48 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/03 19:59:31 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

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
	perturbed = vec_sub(tbn.normal, vec_scale(tbn.tangent, grad_u
				* bump->intensity * 2.0));
	perturbed = vec_sub(perturbed, vec_scale(tbn.bitangent, grad_v
				* bump->intensity * 2.0));
	return (vec_normalize(perturbed));
}

bool	compute_object_tbn_uv(const t_object *obj, t_hit_record *rec,
		t_tbn *tbn, t_uv *uv)
{
	if (obj->type == SPHERE)
		compute_sphere_tbn_uv(obj, rec, tbn, uv);
	else if (obj->type == PLANE)
		compute_plane_tbn_uv(obj, rec, tbn, uv);
	else if (obj->type == CYLINDER)
		compute_cylinder_tbn_uv(obj, rec, tbn, uv);
	else if (obj->type == TRIANGLE)
		compute_triangle_tbn_uv(obj, rec, tbn, uv);
	else if (obj->type == PARABOLOID)
		compute_paraboloid_tbn_uv(obj, rec, tbn, uv);
	else
		return (false);
	return (true);
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
