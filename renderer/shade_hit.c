/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhoura <ralhoura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 18:41:21 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/05 15:58:32 by ralhoura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

t_color	shade_with_lights(t_object *object, t_hit_record *record,
		t_scene *scene, t_color base_color)
{
	t_light	*light;
	t_color	final_color;
	t_color	diffuse;
	t_color	specular;

	final_color = render_ambient(base_color, scene->ambient);
	light = scene->lights;
	while (light)
	{
		diffuse = render_diffuse(base_color, record, scene, light);
		specular = render_specular(object, record, scene, light);
		final_color = color_add(final_color, diffuse);
		final_color = color_add(final_color, specular);
		light = light->next;
	}
	return (color_clamp_rgb(final_color));
}

t_color	get_checker_color(t_object *object, t_point local_p)
{
	if (object->type == SPHERE)
		return (sphere_checker_at(&object->pattern, local_p));
	if (object->type == CYLINDER)
		return (cylinder_checker_at_axis(&object->pattern, local_p,
				object->data.cylinder.axis, object->data.cylinder.height));
	if (object->type == PLANE)
		return (plane_checker_at(&object->pattern, local_p,
				object->data.plane.normal));
	if (object->type == TRIANGLE)
		return (triangle_checker_at_normal(&object->pattern, local_p,
				vec_normalize(vec_cross(
						point_sub_point(object->data.triangle.point_b,
							object->data.triangle.point_a),
						point_sub_point(object->data.triangle.point_c,
							object->data.triangle.point_a)))));
	if (object->type == PARABOLOID)
		return (paraboloid_checker_at_axis(&object->pattern, local_p,
				object->data.paraboloid.axis, object->data.paraboloid.height));
	if (object->pattern.type == PATTERN_CHECKER)
		return (plane_checker_at(&object->pattern, local_p, (t_vec){0.0, 1.0,
				0.0}));
	return (object->pattern.color_a);
}

t_point	pattern_point(t_object *object, t_point point)
{
	t_vec	value;

	if (object->type == SPHERE)
		value = point_sub_point(point, object->data.sphere.center);
	else if (object->type == PLANE)
		value = point_sub_point(point, object->data.plane.point);
	else if (object->type == CYLINDER)
		value = point_sub_point(point, object->data.cylinder.center);
	else if (object->type == TRIANGLE)
		value = point_sub_point(point, object->data.triangle.point_a);
	else if (object->type == PARABOLOID)
		value = point_sub_point(point, object->data.paraboloid.vertex);
	else
		return (point);
	return ((t_point){value.x, value.y, value.z});
}

t_uv	get_object_uv(t_object *object, t_point point)
{
	if (object->type == SPHERE)
		return (sphere_uv(point, object->data.sphere.center,
				object->data.sphere.radius));
	if (object->type == PLANE)
		return (plane_uv(point, object->data.plane.point,
				object->data.plane.normal));
	if (object->type == CYLINDER)
		return (cylinder_uv(point, object->data.cylinder.center,
				object->data.cylinder.axis, object->data.cylinder.height));
	if (object->type == TRIANGLE)
		return (triangle_uv(point, object->data.triangle.point_a,
				object->data.triangle.point_b, object->data.triangle.point_c));
	return (paraboloid_uv(point, object->data.paraboloid.vertex,
			object->data.paraboloid.axis, object->data.paraboloid.height));
}

t_color	shade_hit(t_hit_record *record, t_scene *scene)
{
	t_object	*object;
	t_color		base_color;
	t_point		local_p;

	object = (t_object *)record->object;
	base_color = object->color;
	if (object->color_texture.is_active)
		texture_color_at(&object->color_texture.texture, get_object_uv(object,
				record->point), &base_color);
	if (object->pattern.type == PATTERN_CHECKER)
	{
		local_p = pattern_point(object, record->point);
		base_color = get_checker_color(object, local_p);
	}
	if (object->bump_map.is_active)
		apply_bump_mapping(object, record);
	return (shade_with_lights(object, record, scene, base_color));
}
