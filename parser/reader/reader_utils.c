#include "reader_internal.h"



t_line_node *create_node(char *line)
{
    t_line_node *node;

    node = malloc(sizeof(t_line_node));
    if (!node)
        return (NULL);
    node->line = line;
    node->next = NULL;
    return (node);
}


void append_node(t_line_node **list, t_line_node *new_node)
{

    t_line_node *current;

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

size_t	count_nodes(t_line_node *list)
{
    size_t count;

    count = 0;
    while (list)
    {
        count++;
        list = list->next;
    }
    return (count);
}


void	free_string_array(char **array, size_t used)
{
    size_t i;

    i = 0;
    if (!array)
	    return ;
    while (i < used)
    {
        free(array[i]);
        i++;
    }
    free(array);
}





