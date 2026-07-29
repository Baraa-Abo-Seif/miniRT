#ifndef LEXER_H
# define LEXER_H

# include "token.h"

t_token *lexer_tokenize(char **lines);

void lexer_destroy_tokens(t_token *tokens);

#endif


