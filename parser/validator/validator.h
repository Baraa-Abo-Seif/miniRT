/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:51:38 by bablo             #+#    #+#             */
/*   Updated: 2026/10/22 19:05:16 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATOR_H
# define VALIDATOR_H

#include <stdbool.h>

# include "../lexer/lexer_token.h"
#include "../../utils/utils.h"

typedef struct s_scene_counts
{
	int	ambient;
	int	camera;
	int	light;
}	t_scene_counts;

typedef enum e_token_type t_token_type;

bool	validate_tokens(t_token *tokens);

bool	validate_token_types(t_token *tokens);

bool	validate_arg_count(t_token *tokens);

int	get_expected_arg_count(t_token_type type);
bool	is_valid_arg_count(t_token_type type, size_t actual_count);
bool	update_scene_counts( t_scene_counts *counts, t_token *token);
bool	validate_required_scene_objects( t_scene_counts *counts);

bool	validate_scene_rules(t_token *tokens);

#endif
