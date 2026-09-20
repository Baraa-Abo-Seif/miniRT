#include "renderer.h"



t_color	render_specular(t_object *object,
			t_hit_record *record,
			t_scene *scene,
			t_light *light)
{
	t_vec	light_direction;
	t_vec	incident;
	t_vec	reflection;
	t_vec	view_direction;
	double	specular_factor;
	t_color	result;

	result = (t_color){0.0, 0.0, 0.0};

	if (object->shininess <= 0.0)
		return (result);

	if (is_in_shadow(record, scene, light))
		return (result);

	light_direction = point_sub_point(light->position, record->point);
	light_direction = vec_normalize(light_direction);

	incident = vec_scale(light_direction, -1.0);
	reflection = vec_reflect(incident, record->normal);

	view_direction = point_sub_point(scene->camera.position,
			record->point);
	view_direction = vec_normalize(view_direction);

	specular_factor = vec_dot(reflection, view_direction);
	if (specular_factor < 0.0)
		specular_factor = 0.0;

	specular_factor = pow(specular_factor, object->shininess);
	specular_factor *= light->brightness;

	result = color_scale(light->color, specular_factor);
	return (result);
}



