
#include "lexer_internal.h"


void	destroy_token_list(t_token *list)
{
    t_token *next;
    t_token *current;

    current = list;
    while (current)
    {
        next = current->next;
        if (current->raw_line)
            free(current->raw_line);
        if (current->args)
            free_string_array(current->args);
        free(current);
        current = next;
    }
}





