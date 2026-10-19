/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_string_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 19:30:31 by bablo             #+#    #+#             */
/*   Updated: 2026/10/19 19:30:32 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"
 
void	free_string_array(char **array)
{
    size_t i;

    i = 0;
    if (!array)
	    return ;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}
