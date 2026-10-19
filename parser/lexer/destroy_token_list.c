/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 16:12:41 by bablo             #+#    #+#             */
/*   Updated: 2026/10/19 17:55:25 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lexer_token.h"


void	destroy_token_list(t_token *list)
{
    t_token *next;
    t_token *current;

    current = list;
    while (current)
    {
        next = current->next;
        if (current->raw_line)
            free(current->raw_line);
        if (current->args)
            free_string_array(current->args);
        free(current);
        current = next;
    }
}





