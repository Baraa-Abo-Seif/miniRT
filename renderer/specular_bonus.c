/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhoura <ralhoura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 19:16:28 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/05 15:59:40 by ralhoura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

t_color	render_specular(t_object *object, t_hit_record *record, t_scene *scene,
		t_light *light)
{
	t_vec	reflection;
	double	specular_factor;

	if (object->shininess <= 0.0 || is_in_shadow(record, scene, light))
		return ((t_color){0.0, 0.0, 0.0});
	reflection = vec_reflect(vec_scale(vec_normalize(
					point_sub_point(light->position,
						record->point)), -1.0), record->normal);
	if (vec_dot(record->normal, vec_normalize(point_sub_point(light->position,
					record->point))) <= 0.0)
		return ((t_color){0.0, 0.0, 0.0});
	specular_factor = vec_dot(reflection,
			vec_normalize(point_sub_point(scene->camera.position,
					record->point)));
	if (specular_factor < 0.0)
		specular_factor = 0.0;
	specular_factor = pow(specular_factor, object->shininess);
	specular_factor *= light->brightness;
	return (color_scale(light->color, specular_factor));
}
