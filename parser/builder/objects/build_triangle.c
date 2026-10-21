/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 19:55:38 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/20 19:55:39 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./object_builder.h"

t_object	*build_triangle(const t_token *token)
{
	t_object	*object;

	object = create_object();
	if (!object)
		return (NULL);
	object->type = TRIANGLE;
	object->data.triangle.point_a = parse_point(token->args[0]);
	object->data.triangle.point_b = parse_point(token->args[1]);
	object->data.triangle.point_c = parse_point(token->args[2]);
	if (!parse_color(token->args[3], &object->color))
		return (failed_object(object));
	object->bump_map.intensity = DEFAULT_BUMP_INTENSITY;
	if (!parse_object_bonus(object, token, 3))
		return (failed_object(object));
	return (object);
}
