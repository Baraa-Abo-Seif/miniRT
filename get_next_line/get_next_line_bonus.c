/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:50:23 by babo-sai          #+#    #+#             */
/*   Updated: 2025/11/09 10:51:58 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_chunk(char **chunk)
{
	if (chunk && *chunk)
	{
		free(*chunk);
		*chunk = NULL;
	}
	return (NULL);
}

char	*update_chunk(char **chunk)
{
	char	*new_chunk;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((*chunk)[i] && (*chunk)[i] != '\n')
		i++;
	if (!(*chunk)[i])
		return (free_chunk(chunk));
	i++;
	new_chunk = malloc(sizeof(char) * (ft_strlen(*chunk) - i + 1));
	if (!new_chunk)
		return (free_chunk(chunk));
	while ((*chunk)[i])
		new_chunk[j++] = (*chunk)[i++];
	new_chunk[j] = '\0';
	free(*chunk);
	return (new_chunk);
}

char	*extract_line(char **chunk)
{
	char	*line;
	size_t	i;

	i = 0;
	while ((*chunk)[i] && (*chunk)[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + ((*chunk)[i] == '\n') + 1));
	if (!line)
		return (NULL);
	i = 0;
	while ((*chunk)[i] && (*chunk)[i] != '\n')
	{
		line[i] = (*chunk)[i];
		i++;
	}
	if ((*chunk)[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

int	read_and_save(int fd, char **chunk, char *buffer)
{
	char	*temp;
	ssize_t	bytes;

	if (!empty_beginning(chunk))
		return (-1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		temp = malloc(sizeof(char) * (ft_strlen(*chunk) + bytes + 1));
		if (!temp)
			return (-1);
		ft_strcpy(temp, *chunk);
		ft_strcat(temp, buffer);
		free(*chunk);
		*chunk = temp;
		if (ft_strchr(*chunk, '\n'))
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes < 0)
		return (-1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*chunk[1024];
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (free_chunk(&chunk[fd]));
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free_chunk(&chunk[fd]));
	if (read_and_save(fd, &chunk[fd], buffer) == -1)
	{
		free(buffer);
		return (free_chunk(&chunk[fd]));
	}
	free(buffer);
	if (!chunk[fd] || *chunk[fd] == '\0')
		return (free_chunk(&chunk[fd]));
	line = extract_line(&chunk[fd]);
	if (!line)
		return (free_chunk(&chunk[fd]));
	chunk[fd] = update_chunk(&chunk[fd]);
	return (line);
}
