
#include "cleanup.h"


void	destroy_object_list(t_object *objects)
{
    t_object	*current;
    t_object	*next;

    current = objects;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
}