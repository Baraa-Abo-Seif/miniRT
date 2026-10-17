/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:18:36 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 16:18:37 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../../lib_math/lib_math.h"

typedef struct s_triangle
{
    t_point point_a;
    t_point point_b;
    t_point point_c;
} t_triangle;

#endif