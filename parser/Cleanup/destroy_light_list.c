

#include "cleanup.h"

void	destroy_light_list(t_light *lights)
{
    t_light	*current;
    t_light	*next;

    current = lights;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
}
