/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 20:28:20 by bablo             #+#    #+#             */
/*   Updated: 2026/10/19 20:28:21 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"


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
	if (!array)
		error_msg("Error reading scene file.");
	close(fd);
	return (array);
}

void free_new_node(t_line_node *list,char *line)
{
	get_next_line(-1);
	free(line);
	ft_lstclear(&list,free);
}

char	**read_lines(int fd)
{
    t_line_node		*list;
	t_line_node		*new_node;
	char			*line;
	char			**array;

	list = NULL;
	line = get_next_line(fd);
	if (!line)
		error_msg("Scene file is empty.");
	while (line)
	{
		new_node = ft_lstnew(line);
		if (!new_node)
		{
			free_new_node(list,line);
			return (NULL);
		}
		ft_lstadd_back(&list, new_node);
		line = get_next_line(fd);
		if (!line)
			get_next_line(-1);
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
