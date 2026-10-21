/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:25:16 by bablo             #+#    #+#             */
/*   Updated: 2026/10/21 14:49:21 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_token.h"

t_token *	cleanup_token(t_token *token)
{
    if (!token)
        return  (NULL);
    if (token->raw_line)
        free(token->raw_line);
    if (token->args)
        free_string_array(token->args);
    free(token);
    return (NULL);
}

bool	is_blank_line(const char *line)
{
	while (*line)
	{
		if (!(*line > 7 && *line < 14) || *line == 32)
			return (false);
		line++;
	}
	return (true);
}

char	normalize_whitespace(unsigned int i, char c)
{
	(void)i;
	if ((c > 7 && c < 14))
		return (' ');
	return (c);
}

t_token	*tokenize_line(const char *line, size_t line_number)
{
	char	*normalized_line;
	char	**words;
	t_token	*token;

	if (!line)
		return (NULL);
	normalized_line = ft_strmapi(line, normalize_whitespace);
	if (!normalized_line)
		return (NULL);
	words = ft_split(normalized_line, ' ');
	free(normalized_line);
	if (!words || !words[0])
	{
		free_string_array(words);
		return (NULL);
	}
	token = create_token(line, line_number, words);
	free_string_array(words);
	return (token);
}

void	append_token(t_token **list, t_token *new_token)
{

    t_token *current;

    if (!list || !new_token)
        return ;
    if (!*list)
    {
        *list = new_token;
        return ;
    }
    current = *list;
    while (current->next)
        current = current->next;
    current->next = new_token;
    
}
