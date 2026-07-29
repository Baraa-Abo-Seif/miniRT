#include "reader_internal.h"

void destroy_line_list(t_line_node *list)
{
    t_line_node *next;
    t_line_node *current;

    current = list;
    while (current)
    {
        next = current->next;
        if (current->line)
            free(current->line);
        free(current);
        current = next;
    }
}
