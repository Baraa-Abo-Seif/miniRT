/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:19:40 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 16:35:58 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_H
#define AMBIENT_H

#include "../lib_math/lib_math.h"


typedef struct s_ambient
{
    double  ratio;
    t_color color;
} t_ambient;

#endif

