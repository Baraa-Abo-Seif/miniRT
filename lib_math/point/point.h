/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:42:32 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 14:42:34 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "../vector/vector.h"

typedef struct s_point
{
    double x;
    double y;
    double z;
} t_point;

t_point	point_add_vec(t_point point, t_vec vec);

t_point	point_sub_vec(t_point point, t_vec vec);

t_vec	point_sub_point(t_point a, t_point b);

#endif