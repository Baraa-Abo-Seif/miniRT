#include "reader_internal.h"

 char	**read_lines(int fd)
{
    t_line_node		*list;
	t_line_node		*new_node;
	char			*line;
	char			**array;


	list = NULL;
	while ((line = get_next_line(fd)))
	{
		new_node = create_node(line);
		if (!new_node)
		{
			free(line);
			destroy_line_list(list);
			return (NULL);
		}
		append_node(&list, new_node);
	}
	array = list_to_array(list);
	destroy_line_list(list);
	return (array);
}