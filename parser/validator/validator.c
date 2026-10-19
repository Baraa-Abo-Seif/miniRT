/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:47:56 by bablo             #+#    #+#             */
/*   Updated: 2026/10/19 18:48:17 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "validator.h"

bool	validate_tokens(t_token *tokens)
{
    if (!validate_token_types(tokens))
	    return (false);
    if (!validate_arg_count(tokens))
        return (false);
    if (!validate_scene_rules(tokens))
        return (false);
    return (true);
}
