#include "renderer.h"

t_color	shade_hit(t_hit_record *record, t_scene *scene)
{
	t_object	*object;
	t_light		*light;
	t_color		final_color;
	t_color		diffuse;

	object = (t_object *)record->object;
	light = scene->lights;
	final_color = render_ambient(object->color, scene->ambient);

	while (light)
	{
		diffuse = render_diffuse(object->color, record, scene, light);
		final_color = color_add(final_color, diffuse);
		light = light->next;
	}
	final_color = color_clamp_rgb(final_color);
	return (final_color);
}