/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 19:52:09 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/20 19:52:26 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./object_builder.h"

t_object	*build_sphere(const t_token *token)
{
	t_object	*object;

	object = create_object();
	if (!object)
		return (NULL);
	object->type = SPHERE;
	object_setup(object, token);
	if (!check_positive(object->data.sphere.radius))
		return (failed_object(object));
	object->data.sphere.radius /= 2.0;
	if (!parse_color(token->args[2], &object->color))
		return (failed_object(object));
	object->bump_map.intensity = DEFAULT_BUMP_INTENSITY;
	if (!parse_object_bonus(object, token, 2))
		return (failed_object(object));
	return (object);
}
