/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_object_tbn_uv_for_each_object.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 20:01:08 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/03 18:00:59 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

void	compute_sphere_tbn_uv(const t_object *obj, t_hit_record *rec,
		t_tbn *tbn, t_uv *uv)
{
	*uv = sphere_uv(rec->point, obj->data.sphere.center,
			obj->data.sphere.radius);
	*tbn = sphere_tbn(rec->normal);
}

void	compute_plane_tbn_uv(const t_object *obj, t_hit_record *rec, t_tbn *tbn,
		t_uv *uv)
{
	*uv = plane_uv(rec->point, obj->data.plane.point, rec->normal);
	*tbn = plane_tbn(rec->normal);
}

void	compute_cylinder_tbn_uv(const t_object *obj, t_hit_record *rec,
		t_tbn *tbn, t_uv *uv)
{
	*uv = cylinder_uv(rec->point, obj->data.cylinder.center,
			obj->data.cylinder.axis, obj->data.cylinder.height);
	*tbn = cylinder_tbn(obj->data.cylinder.axis, rec->normal);
}

void	compute_triangle_tbn_uv(const t_object *obj, t_hit_record *rec,
		t_tbn *tbn, t_uv *uv)
{
	*uv = triangle_uv(rec->point, obj->data.triangle.point_a,
			obj->data.triangle.point_b, obj->data.triangle.point_c);
	*tbn = triangle_tbn(obj->data.triangle.point_a, obj->data.triangle.point_b,
			rec->normal);
}

void	compute_paraboloid_tbn_uv(const t_object *obj, t_hit_record *rec,
		t_tbn *tbn, t_uv *uv)
{
	*uv = paraboloid_uv(rec->point, obj->data.paraboloid.vertex,
			obj->data.paraboloid.axis, obj->data.paraboloid.height);
	*tbn = paraboloid_tbn(obj->data.paraboloid.axis, rec->normal);
}
