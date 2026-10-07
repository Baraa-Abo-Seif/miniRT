#include "renderer.h"
#include <stdio.h>
#include "../pattern/pattern.h"

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
// #define PLANE_CHECKER_SCALE 0.1  // كلما صغرت القيمة كَبُر حجم المربع

// t_color plane_checker_at(t_pattern *pattern, t_point point)
// {
//     long cell_x;
//     long cell_z;

//     // استخدام مقياس أكبر لتقليل ظاهرة Moiré Pattern
//     cell_x = (long)floor(point.x * PLANE_CHECKER_SCALE);
//     cell_z = (long)floor(point.z * PLANE_CHECKER_SCALE);

//     if ((cell_x + cell_z) % 2 == 0)
//         return (pattern->color_a);
//     return (pattern->color_b);
// }


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
		t_point local_p = pattern_point(object, record->point);

		if (object->type == SPHERE)
			base_color = sphere_checker_at(&object->pattern, local_p);
		else if (object->type == CYLINDER)
			base_color = cylinder_checker_at_axis(&object->pattern, local_p,
					object->data.cylinder.axis,
					object->data.cylinder.height);
		else if (object->type == PLANE)
			base_color = plane_checker_at(&object->pattern, local_p,
					object->data.plane.normal);
		else if (object->type == TRIANGLE)
		{
			t_vec edge_one = point_sub_point(object->data.triangle.point_b,
					object->data.triangle.point_a);
			t_vec edge_two = point_sub_point(object->data.triangle.point_c,
					object->data.triangle.point_a);
			t_vec normal = vec_normalize(vec_cross(edge_one, edge_two));
			base_color = triangle_checker_at_normal(&object->pattern, local_p,
					normal);
		}
		else if (object->type == PARABOLOID)
			base_color = paraboloid_checker_at_axis(&object->pattern, local_p,
					object->data.paraboloid.axis,
					object->data.paraboloid.height);
		else
			base_color = pattern_at(&object->pattern, local_p);
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
