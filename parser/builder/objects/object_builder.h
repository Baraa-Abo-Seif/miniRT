/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_builder.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 15:11:06 by bablo             #+#    #+#             */
/*   Updated: 2026/10/22 19:14:43 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_BUILDER_H
# define OBJECT_BUILDER_H

# include "../../../scene/object.h"
# include "../../../utils/utils.h"
# include "../../converter/converter.h"
# include "../../lexer/lexer_token.h"
# include "../../parsering_utils/parsing_utils.h"

t_object	*create_object(void);

t_object	*build_cylinder(const t_token *token);

t_object	*build_paraboloid(const t_token *token);

t_object	*build_plane(const t_token *token);

t_object	*build_sphere(const t_token *token);

t_object	*build_triangle(const t_token *token);

void		parse_checker_pattern(t_object *object, char *const *args,
				size_t *i);
void		parse_color_texture(t_object *object, const char *arg);
void		parse_bump_map(t_object *object, const char *arg);
bool		parse_object_bonus(t_object *object, const t_token *token,
				size_t color_index);

t_object	*failed_object(t_object *object);
void		object_setup(t_object *object, const t_token *token);
void		failled_massage(const char *msg, char **parts);

#endif
