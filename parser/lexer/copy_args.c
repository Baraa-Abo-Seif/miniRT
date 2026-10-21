/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 16:31:18 by bablo             #+#    #+#             */
/*   Updated: 2026/10/21 14:49:29 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_token.h"

char	**copy_args(char **words)
{
    size_t args_count;
    char **copy;
    size_t index;

    index = 1;
    args_count = 1;
    if (!words || !words[0])
        return (NULL);
    while (words[args_count])
        args_count++;
    copy = ft_calloc((args_count) , sizeof(char *));
    if (!copy)
        return (NULL);
    while (words[index])
    {
        copy[index - 1] = ft_strdup(words[index]);
        if (!copy[index - 1])
        {
            free_string_array(copy);
            return (NULL);
        }
        index++;
    }
    copy[args_count - 1] = NULL;
    return (copy);
}

