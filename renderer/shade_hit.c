#include "renderer.h"
#include <stdio.h>

static t_point	vec_to_pattern_point(t_vec value)
{
	return ((t_point){value.x, value.y, value.z});
}

static t_point	pattern_point(t_object *object, t_point point)
{
	if (object->type == SPHERE)
		return (vec_to_pattern_point(point_sub_point(point,
			object->data.sphere.center)));
	if (object->type == PLANE)
		return (vec_to_pattern_point(point_sub_point(point,
			object->data.plane.point)));
	if (object->type == CYLINDER)
		return (vec_to_pattern_point(point_sub_point(point,
			object->data.cylinder.center)));
	if (object->type == TRIANGLE)
		return (vec_to_pattern_point(point_sub_point(point,
			object->data.triangle.point_a)));
	if (object->type == PARABOLOID)
		return (vec_to_pattern_point(point_sub_point(point,
			object->data.paraboloid.vertex)));
	return (point);
}

t_color	shade_hit(t_hit_record *record, t_scene *scene)
{
	t_object	*object;
	t_light		*light;
	t_color		final_color;
	t_color	base_color;
	t_color		diffuse;
	t_color	specular;

	object = (t_object *)record->object;
	base_color = object->color;
	if (object->pattern.type == PATTERN_CHECKER)
	{
		if (object->type == SPHERE)
			base_color = sphere_checker_at(&object->pattern,
				pattern_point(object, record->point));
		else
			base_color = pattern_at(&object->pattern,
				pattern_point(object, record->point));
	}
	
	light = scene->lights;
	final_color = render_ambient(base_color, scene->ambient);

	while (light)
	{
		diffuse = render_diffuse(base_color, record, scene, light);
		specular = render_specular(object, record, scene, light);


		final_color = color_add(final_color, diffuse);
		final_color = color_add(final_color, specular);

		light = light->next;
	}
	final_color = color_clamp_rgb(final_color);

	return (final_color);
}

