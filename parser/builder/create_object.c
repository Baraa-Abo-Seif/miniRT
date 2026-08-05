#include "builder_internal.h"


t_object	*create_object()
{
    t_object	*object;

    object = malloc(sizeof(t_object));
    if (!object)
        return (NULL);
    ft_bzero(object, sizeof(t_object));
    return (object);
}