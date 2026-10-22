/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 18:49:23 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/22 18:49:24 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builder.h"

t_scene	*build_scene(t_token *tokens)
{
	t_scene	*scene;
	t_token	*current;

	current = tokens;
	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
	{
		error_msg("Failed to allocate memory for scene");
		return (NULL);
	}
	while (current)
	{
		if (!process_scene_token(scene, current))
		{
			destroy_scene(scene);
			return (NULL);
		}
		current = current->next;
	}
	return (scene);
}
