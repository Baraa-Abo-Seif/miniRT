
#include "lexer_internal.h"



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





