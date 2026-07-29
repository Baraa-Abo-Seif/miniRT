#ifndef READER_INTERNAL_H
#define READER_INTERNAL_H


#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "../../minirt.h"

#include "./reader.h"



typedef struct s_line_node
{
    char                *line;
    struct s_line_node  *next;
} t_line_node;


t_line_node *create_node(char *line);
void append_node(t_line_node **list, t_line_node *new_node);
size_t	count_nodes(t_line_node *list);
void	free_string_array(char **array, size_t used);
char **list_to_array(t_line_node *list);
char	**read_lines(int fd);
void destroy_line_list(t_line_node *list);


#endif
