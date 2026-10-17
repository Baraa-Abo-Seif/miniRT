/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:18:29 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 16:35:44 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
#define SPHERE_H

#include "../../lib_math/lib_math.h"


typedef struct s_sphere
{
    t_point center; // center point of the sphere
    double  radius; // radius of the sphere
} t_sphere;



#endif
