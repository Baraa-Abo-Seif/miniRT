/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cross.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:52:12 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 14:52:15 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"



t_vec vec_cross(t_vec a, t_vec b)
{
    t_vec result;

    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return (result);

}











