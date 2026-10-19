/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 12:56:52 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/19 19:09:04 by bablo            ###   ########.fr       */
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
