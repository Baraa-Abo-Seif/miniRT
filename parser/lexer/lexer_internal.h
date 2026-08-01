#ifndef LEXER_INTERNAL_H
# define LEXER_INTERNAL_H

# include <stdlib.h>

# include "../../minirt.h"

# include "lexer.h"


t_token_type	get_token_type(const char *identifier);
t_token	*create_token(const char *raw_line, size_t line_number, char **words);
t_token	*cleanup_token(t_token *token);
void	append_token(t_token **list, t_token *new_token);
t_token	*tokenize_line( const char *line, size_t line_number);



#endif