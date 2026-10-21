/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 16:57:24 by bablo             #+#    #+#             */
/*   Updated: 2026/10/21 14:49:28 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_token.h"


t_token	*create_token(const char *raw_line, size_t line_number, char **words)
{
    t_token *token;

    token = ft_calloc(1, sizeof(t_token));
    if (!token || !words || !words[0])
        return (NULL);
    token->raw_line = ft_strdup(raw_line);
    if (!token->raw_line)
        return (cleanup_token(token));
    token->type = get_token_type(words[0]);
    token->args = copy_args(words);
    if (!token->args)
        return (cleanup_token(token));
    token->line_number = line_number;
    token->next = NULL;
    return (token);
}

