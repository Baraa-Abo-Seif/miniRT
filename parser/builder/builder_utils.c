#include "builder_internal.h"

t_object	*create_object(t_object_type type)
{
    t_object	*object;

    object = malloc(sizeof(t_object));
    if (!object)
        return (NULL);
    object->type = type;
    object->next = NULL;
    return (object);
}

void	append_object(t_object **list, t_object *new_object)
{
    t_object	*current;

    if (!list || !new_object)
        return ;
    if (!*list)
    {
        *list = new_object;
        return ;
    }
    current = *list;
    while (current->next)
        current = current->next;
    current->next = new_object;
}

t_light	*create_light(void)
{
    t_light	*light;

    light = malloc(sizeof(t_light));
    if (!light)
        return (NULL);
    light->next = NULL;
    return (light);
}

void	append_light(t_light **list, t_light *new_light)
{
    t_light	*current;

    if (!list || !new_light)
        return ;
    if (!*list)
    {
        *list = new_light;
        return ;
    }
    current = *list;
    while (current->next)
        current = current->next;
    current->next = new_light;
}
