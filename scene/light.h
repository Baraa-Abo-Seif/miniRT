/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:25:06 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 16:25:40 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
#define LIGHT_H


#include "../lib_math/lib_math.h"

typedef struct s_light
{
    t_point position;
    double  brightness;
    t_color color;
    struct s_light *next;
} t_light;



#endif

