/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_token_types.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:19:45 by bablo             #+#    #+#             */
/*   Updated: 2026/10/19 18:19:46 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "validator.h"

bool	validate_token_types(t_token *tokens)
{
    t_token	*current;

    current = tokens;
    while (current)
    {
        if (current->type == TOKEN_UNKNOWN)
                return (error_msg_line(current->line_number,
                     "Unknown object type."));
        current = current->next;
    }
    return (true);
}
