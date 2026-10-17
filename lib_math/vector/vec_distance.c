/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:53:39 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 14:53:44 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double vec_distance(t_vec a, t_vec b)
{
    t_vec victor;
    double distance;

    victor = vec_sub(a, b);
    distance = vec_length(victor);
    return (distance);
}


