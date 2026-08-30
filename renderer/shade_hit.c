#include "renderer.h"
#include <stdio.h>

t_color	shade_hit(t_hit_record *record, t_scene *scene)
{
	t_object	*object;
	t_light		*light;
	t_color		final_color;
	t_color		diffuse;

	object = (t_object *)record->object;
	
	light = scene->lights;
	final_color = render_ambient(object->color, scene->ambient);

	printf("OBJECT = %f %f %f\n",
		object->color.r,
		object->color.g,
		object->color.b);
	printf("AMBIENT = %f %f %f\n",
		final_color.r,
		final_color.g,
		final_color.b);

	while (light)
	{
		diffuse = render_diffuse(object->color, record, scene, light);
		printf("DIFFUSE = %f %f %f\n",
			diffuse.r,
			diffuse.g,
			diffuse.b);
		final_color = color_add(final_color, diffuse);
		light = light->next;
	}
	final_color = color_clamp_rgb(final_color);
	printf("FINAL = %f %f %f\n",
		final_color.r,
		final_color.g,
		final_color.b);

	return (final_color);
}

