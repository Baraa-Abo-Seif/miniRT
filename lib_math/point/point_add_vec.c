/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_add_vec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:42:19 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 14:42:20 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"


t_point	point_add_vec(t_point point, t_vec vec)
{
    t_point result;

    result.x = point.x + vec.x;
    result.y = point.y + vec.y;
    result.z = point.z + vec.z;

    return result;
}

