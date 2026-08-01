#ifndef LEXER_H
# define LEXER_H

# include "token.h"

t_token	*tokenize(char **lines);
void	destroy_token_list(t_token *list);

#endif
