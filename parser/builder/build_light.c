/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 17:20:44 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/22 17:20:45 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builder.h"

t_light	*build_light(const t_token *token)
{
	t_light	*light;

	light = ft_calloc(1, sizeof(t_light));
	if (!light)
	{
		error_msg("Failed to allocate memory for light");
		return (NULL);
	}
	light->position = parse_point(token->args[0]);
	light->brightness = ft_atof(token->args[1]);
	if (!check_positive(light->brightness) || !check_ratio(light->brightness))
	{
		free(light);
		return (NULL);
	}
	if (!parse_color(token->args[2], &light->color))
	{
		free(light);
		return (NULL);
	}
	return (light);
}

