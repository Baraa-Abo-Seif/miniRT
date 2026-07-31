#include "lexer_internal.h"


void append_token(t_token **list, t_token *new_node)
{
    t_token *current;

    if (!list || !new_node)
        return ;
    if (!*list)
    {
        *list = new_node;
        return ;
    }
    current = *list;
    while (current->next)
        current = current->next;
    current->next = new_node;
}
