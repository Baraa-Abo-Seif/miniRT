/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:29:01 by bablo             #+#    #+#             */
/*   Updated: 2026/10/21 14:49:23 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdbool.h>
# include "../../minirt.h"
# include "../parsering_utils/parsing_utils.h"
#include "../../Libft/libft.h"


typedef enum e_token_type
{
    TOKEN_AMBIENT,
    TOKEN_CAMERA,
    TOKEN_LIGHT,
    TOKEN_MULTI_LIGHT,
    TOKEN_SPHERE,
    TOKEN_PLANE,
    TOKEN_CYLINDER,
    TOKEN_TRIANGLE,
    TOKEN_PARABOLOID,
    TOKEN_UNKNOWN
} t_token_type;

typedef struct s_token
{
	t_token_type	type;			// Token category.
	char			*raw_line;		// Original line (for error reporting).
	char			**args;			// Arguments extracted from the line.
	size_t			line_number;	// Original line number.
	struct s_token	*next;			// Next token in the list.
}	t_token;


void	destroy_token_list(t_token *list);

t_token_type	get_token_type(const char *identifier);

t_token	*cleanup_token(t_token *token);
bool	is_blank_line(const char *line);
char	normalize_whitespace(unsigned int i, char c);
t_token	*tokenize_line(const char *line, size_t line_number);
void	append_token(t_token **list, t_token *new_token);

char	**copy_args(char **words);

t_token	*create_token(const char *raw_line, size_t line_number, char **words);

t_token	*tokenize(char **lines);

#endif
