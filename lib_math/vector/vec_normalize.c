/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:54:41 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 14:54:45 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"


t_vec vec_normalize(t_vec v)
{
    double length;
    t_vec result;

    length = vec_length(v);
    if (length == 0)
    {
        result.x = 0;
        result.y = 0;
        result.z = 0;
        return (result);
    }
    result.x = v.x / length;
    result.y = v.y / length;
    result.z = v.z / length;
    return (result);
}




