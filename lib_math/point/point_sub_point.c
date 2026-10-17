/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_sub_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:42:22 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 14:42:24 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"



t_vec	point_sub_point(t_point a, t_point b)
{
    t_vec result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;

    return result;
}
