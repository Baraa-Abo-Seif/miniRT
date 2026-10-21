/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:54:36 by bablo             #+#    #+#             */
/*   Updated: 2026/10/21 14:54:39 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./object_builder.h"

t_object	*build_cylinder(const t_token *token)
{
	t_object	*object;
	double		diameter;
	double		height;

	object = create_object();
	if (!object)
		return (NULL);
	object->type = CYLINDER;
	object_setup(object, token);
	if (!check_normal(object->data.cylinder.axis))
		return (failed_object(object));
	diameter = ft_atof(token->args[2]);
	if (!check_positive(diameter))
		return (failed_object(object));
	object->data.cylinder.radius = diameter / 2.0;
	height = ft_atof(token->args[3]);
	if (!check_positive(height))
		return (failed_object(object));
	object->data.cylinder.height = height;
	if (!parse_color(token->args[4], &object->color))
		return (failed_object(object));
	object->bump_map.intensity = DEFAULT_BUMP_INTENSITY;
	if (!parse_object_bonus(object, token, 4))
		return (failed_object(object));
	return (object);
}

