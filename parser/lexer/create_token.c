
#include "lexer_internal.h"


t_token	*create_token(const char *raw_line, size_t line_number, char **words)
{
    t_token *token;

    token = malloc(sizeof(t_token));
    if (!token)
        return (NULL);
    token->raw_line = ft_strdup(raw_line);
    if (!token->raw_line)
        return (cleanup_token(token));
    if (!words || !words[0])
        return (cleanup_token(token));
    token->type = get_token_type(words[0]);
    token->args = copy_args(words);
    if (!token->args)
        return (cleanup_token(token));
    token->line_number = line_number;
    token->next = NULL;
    return (token);
}

