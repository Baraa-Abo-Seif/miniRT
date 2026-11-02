#include "renderer.h"

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



static t_vec	triangle_pattern_normal(t_triangle triangle)
{
	t_vec	edge_one;
	t_vec	edge_two;

	edge_one = point_sub_point(triangle.point_b, triangle.point_a);
	edge_two = point_sub_point(triangle.point_c, triangle.point_a);
	return (vec_normalize(vec_cross(edge_one, edge_two)));
}


static t_color	get_checker_color(t_object *object, t_point local_p)
{
	if (object->type == SPHERE)
		return (sphere_checker_at(&object->pattern, local_p));
	if (object->type == CYLINDER)
		return (cylinder_checker_at_axis(&object->pattern, local_p,
				object->data.cylinder.axis,
				object->data.cylinder.height));
	if (object->type == PLANE)
		return (plane_checker_at(&object->pattern, local_p,
				object->data.plane.normal));
	if (object->type == TRIANGLE)
		return (triangle_checker_at_normal(&object->pattern, local_p,
				triangle_pattern_normal(object->data.triangle)));
	if (object->type == PARABOLOID)
		return (paraboloid_checker_at_axis(&object->pattern, local_p,
				object->data.paraboloid.axis,
				object->data.paraboloid.height));
	return (pattern_at(&object->pattern, local_p));
}



static t_color	shade_with_lights(t_object *object,
		t_hit_record *record, t_scene *scene, t_color base_color)
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
static t_uv	get_object_uv(t_object *object, t_point point)
{
	if (object->type == SPHERE)
		return (sphere_uv(point, object->data.sphere.center,
				object->data.sphere.radius));
	if (object->type == PLANE)
		return (plane_uv(point, object->data.plane.point,
				object->data.plane.normal));
	if (object->type == CYLINDER)
		return (cylinder_uv(point, object->data.cylinder.center,
				object->data.cylinder.axis,
				object->data.cylinder.height));
	if (object->type == TRIANGLE)
		return (triangle_uv(point, object->data.triangle.point_a,
				object->data.triangle.point_b,
				object->data.triangle.point_c));
	return (paraboloid_uv(point, object->data.paraboloid.vertex,
			object->data.paraboloid.axis,
			object->data.paraboloid.height));
}

static void	apply_object_pattern(t_object *object, t_point point,
		t_color *base_color)
{
	t_point	local_p;

	if (object->pattern.type != PATTERN_CHECKER)
		return ;
	local_p = pattern_point(object, point);
	*base_color = get_checker_color(object, local_p);
}

t_color	shade_hit(t_hit_record *record, t_scene *scene)
{
	t_object	*object;
	t_color		base_color;

	object = (t_object *)record->object;
	base_color = object->color;
	if (object->color_texture.is_active)
		texture_color_at(&object->color_texture.texture,
			get_object_uv(object, record->point), &base_color);
	apply_object_pattern(object, record->point, &base_color);
	if (object->bump_map.is_active)
		apply_bump_mapping(object, record);
	return (shade_with_lights(object, record, scene, base_color));
}

