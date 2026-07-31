#include "lexer_internal.h"


void destroy_token(t_token *token)
{
    int i;

    if (!token)
        return ;
    i = 0;
    while (i < token->arg_count)
    {
        free(token->args[i]);
        i++;
    }
    free(token->args);
    free(token);
}


void lexer_destroy_tokens(t_token *tokens)
{
    t_token *next;
    t_token *current;

    current = tokens;
    while (current)
    {
        next = current->next;
        destroy_token(current);
        current = next;
    }
}
