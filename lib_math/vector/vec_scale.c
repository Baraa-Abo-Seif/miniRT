/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:55:27 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 14:55:28 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec vec_scale(t_vec a, double k)
{
    t_vec result;

    result.x = a.x * k;
    result.y = a.y * k;
    result.z = a.z * k;
    return (result);
}




