/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:52:42 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 14:52:43 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "vector.h"

t_vec vec_sub(t_vec a, t_vec b)
{
    t_vec result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return (result);
}



