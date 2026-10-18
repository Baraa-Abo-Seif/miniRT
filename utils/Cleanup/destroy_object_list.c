
#include "cleanup.h"


void	destroy_object_list(t_object *objects)
{
    t_object	*current;
    t_object	*next;

    current = objects;
    while (current)
    {
        next = current->next;
        bump_map_destroy(NULL, &current->bump_map);
        color_texture_destroy(NULL, &current->color_texture);
        free(current);
        current = next;
    }
}