#include "lexer_internal.h"


t_token *create_token(char **args, int arg_count, int line_num)
{
    t_token *token;

    token = malloc(sizeof(t_token));
    if (!token)
        return (NULL);
    token->identifier = args[0];
    token->args = args;
    token->arg_count = arg_count;
    token->line = line_num;
    token->next = NULL;
    return (token);
}
