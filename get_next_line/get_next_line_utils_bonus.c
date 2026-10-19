/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:30:14 by babo-sai          #+#    #+#             */
/*   Updated: 2025/11/04 15:34:58 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	index;

	if (!s)
		return (NULL);
	index = 0;
	while (s[index])
	{
		if (s[index] == (char)c)
			return ((char *)&s[index]);
		index++;
	}
	if (c == '\0')
		return ((char *)&s[index]);
	return (NULL);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	index;

	index = 0;
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, const char *src)
{
	size_t	dest_len;
	size_t	index;

	dest_len = ft_strlen(dest);
	index = 0;
	while (src[index])
	{
		dest[dest_len + index] = src[index];
		index++;
	}
	dest[dest_len + index] = '\0';
	return (dest);
}

char	*empty_beginning(char **chunk)
{
	if (!*chunk)
	{
		*chunk = malloc(1);
		if (!*chunk)
			return (NULL);
		(*chunk)[0] = '\0';
	}
	return (*chunk);
}
