/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:28:21 by bablo             #+#    #+#             */
/*   Updated: 2026/10/19 17:28:22 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_token.h"

t_token	*tokenize(char **lines)
{
    t_token *list;
    t_token *new_token;
    size_t  line_number;

    list = NULL;
    line_number = 0;
    while (lines && lines[line_number])
    {
        if (is_blank_line(lines[line_number]))
        {
            line_number++;
            continue;
        }   
        new_token =  tokenize_line(lines[line_number], line_number + 1);
        if (!new_token)
        {
            destroy_token_list(list);
            return (NULL);
        }
        append_token(&list, new_token);
        line_number++;
    }
    return (list);
}
