/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:17:16 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/03 20:01:09 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	destroy_object_list(t_object *objects)
{
	t_object	*current;
	t_object	*next;

	current = objects;
	while (current)
	{
		next = current->next;
		bump_map_destroy(NULL, &current->bump_map);
		color_texture_destroy(NULL, &current->color_texture);
		free(current);
		current = next;
	}
}

void	destroy_light_list(t_light *lights)
{
	t_light	*current;
	t_light	*next;

	current = lights;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	destroy_scene(t_scene *scene)
{
	if (!scene)
		return ;
	destroy_light_list(scene->lights);
	destroy_object_list(scene->objects);
	free(scene);
}
