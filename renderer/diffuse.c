
#include "renderer.h"

t_color	render_diffuse(t_color object_color,t_hit_record *record,t_scene *scene,t_light *light)
{
    t_vec	light_direction;
    double	intensity;
    t_color	result;

    if (is_in_shadow(record, scene, light))
	    return ((t_color){0.0, 0.0, 0.0});

    light_direction = point_sub_point(light->position, record->point);
    light_direction = vec_normalize(light_direction);

    intensity = vec_dot(record->normal, light_direction);
    if (intensity < 0.0)
        intensity = 0.0;

    intensity *= light->brightness;
	result = color_multiply(object_color, light->color);
	result = color_scale(result, intensity);

	return (result);
}



