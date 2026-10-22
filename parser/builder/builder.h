/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 18:54:14 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/22 19:14:55 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDER_H
# define BUILDER_H

# include "./objects/object_builder.h"

typedef struct s_token t_token;

bool	build_ambient(const t_token *token, t_ambient *ambient);

bool	build_camera(const t_token *token, t_camera *camera);

t_light *build_light(const t_token *token);

t_object    *build_object(const t_token *token);

t_scene	*build_scene(t_token *tokens);

void	append_object(t_scene *scene, t_object *object);
bool	add_object_to_scene(t_scene *scene, const t_token *token);
void	append_light(t_scene *scene, t_light *light);
bool	add_light_to_scene(t_scene *scene, const t_token *token);
int	process_scene_token(t_scene *scene, t_token *token);

#endif
