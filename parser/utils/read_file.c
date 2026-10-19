#include "./reader.h"


char	**read_file(const char *filename)
{
	int		fd;
	char	**array;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		if (errno == EACCES)
			error_msg("Cannot read scene file: permission denied.");
		else if (errno == ENOENT)
			error_msg("Scene file does not exist.");
		else
			error_msg("Cannot open scene file.");
		return (NULL);
	}

	array = read_lines(fd);
	close(fd);

	return (array);
}

char	**read_lines(int fd)
{
    t_line_node		*list;
	t_line_node		*new_node;
	char			*line;
	char			**array;


	list = NULL;
	while ((line = get_next_line(fd)))
	{
		new_node = ft_lstnew(line);
		if (!new_node)
		{
			free(line);
			ft_lstclear(&list,free);
			return (NULL);
		}
		ft_lstadd_back(&list, new_node);
	}
	array = list_to_array(list);
	ft_lstclear(&list,free);
	return (array);
}


char **list_to_array(t_line_node *list)
{
    char **arr;
    t_line_node *current;
    size_t num_nodes;
    size_t index;

    index = 0;
    num_nodes = ft_lstsize(list);
    current = list;
    arr = ft_calloc((num_nodes + 1), sizeof(char *));
    if (!arr)
        return (NULL);
    while(current)
    {
        arr[index] = ft_strdup((char *)current->content);
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
