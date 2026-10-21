/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_paraboloid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:59:14 by bablo             #+#    #+#             */
/*   Updated: 2026/10/21 14:59:15 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "./object_builder.h"

t_object	*build_paraboloid(const t_token *token)
{
	t_object	*object;
	double		diameter;

	object = create_object();
	if (!object)
		return (NULL);
	object->type = PARABOLOID;
	object_setup(object, token);
	if (!check_normal(object->data.paraboloid.axis))
		return (failed_object(object));
	diameter = ft_atof(token->args[2]);
	if (!check_positive(diameter))
		return (failed_object(object));
	object->data.paraboloid.radius = diameter / 2.0;
	object->data.paraboloid.height = ft_atof(token->args[3]);
	if (!check_positive(object->data.paraboloid.height))
		return (failed_object(object));
	if (!parse_color(token->args[4], &object->color))
		return (failed_object(object));
	object->bump_map.intensity = DEFAULT_BUMP_INTENSITY;
	if (!parse_object_bonus(object, token, 4))
		return (failed_object(object));
	return (object);
}
