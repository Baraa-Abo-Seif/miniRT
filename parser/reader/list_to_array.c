#include "reader_internal.h"



char **list_to_array(t_line_node *list)
{
    char **arr;
    t_line_node *current;
    size_t num_nodes;
    size_t index;

    index = 0;
    num_nodes = count_nodes(list);
    current = list;
    arr = ft_calloc((num_nodes + 1), sizeof(char *));
    if (!arr)
        return (NULL);
    while(current)
    {
        arr[index] = ft_strdup(current->line);
        if (!arr[index])
        {
            free_string_array(arr);
            return (NULL);
        }
        current = current->next;
        index++;
    }
    arr[num_nodes] = NULL;
    return (arr);
}





