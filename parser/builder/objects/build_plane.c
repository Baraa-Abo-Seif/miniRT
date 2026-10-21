/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 19:49:02 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/21 15:01:14 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./object_builder.h"

t_object	*build_plane(const t_token *token)
{
	t_object	*object;

	object = create_object();
	if (!object)
		return (NULL);
	object->type = PLANE;
	object_setup(object, token);
	if (!check_normal(object->data.plane.normal))
		return (failed_object(object));
	if (!parse_color(token->args[2], &object->color))
		return (failed_object(object));
	object->bump_map.intensity = DEFAULT_BUMP_INTENSITY;
	if (!parse_object_bonus(object, token, 2))
		return (failed_object(object));
	return (object);
}
