/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 15:10:41 by bablo             #+#    #+#             */
/*   Updated: 2026/10/21 15:10:46 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./object_builder.h"

t_object	*create_object()
{
    t_object	*object;

    object =  ft_calloc(sizeof(t_object),1);
    if (!object)
    {
        error_msg("Failed to create object");
        return (NULL);
    }
    return (object);
}
