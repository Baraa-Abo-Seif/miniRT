/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 18:54:02 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/22 18:54:03 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builder.h"

void	append_object(t_scene *scene, t_object *object)
{
    t_object	*current;

    if (!scene || !object)
        return ;
    if (!scene->objects)
    {
        scene->objects = object;
        return ;
    }
    current = scene->objects;
    while (current->next)
        current = current->next;
    current->next = object;
}

bool	add_object_to_scene(t_scene *scene, const t_token *token)
{
	t_object	*object;

	if (!scene || !token)
		return (false);
	object = build_object(token);
	if (!object)
		return (false);
	append_object(scene, object);
	return (true);
}

void	append_light(t_scene *scene, t_light *light)
{
    t_light	*current;

    if (!scene || !light)
        return ;
    if (!scene->lights)
    {
        scene->lights = light;
        return ;
    }
    current = scene->lights;
    while (current->next)
        current = current->next;
    current->next = light;
}

bool	add_light_to_scene(t_scene *scene, const t_token *token)
{
	t_light	*light;

	if (!scene || !token)
		return (false);
	light = build_light(token);
	if (!light)
		return (false);
	append_light(scene, light);
	return (true);
}

int	process_scene_token(t_scene *scene, t_token *token)
{
	if (token->type == TOKEN_AMBIENT)
		return (build_ambient(token, &scene->ambient));
	else if (token->type == TOKEN_CAMERA)
		return (build_camera(token, &scene->camera));
	else if (token->type == TOKEN_LIGHT
		|| token->type == TOKEN_MULTI_LIGHT)
		return (add_light_to_scene(scene, token));
	return (add_object_to_scene(scene, token));
}
