/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:18:00 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/22 18:44:50 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
#define CYLINDER_H

#include "../../lib_math/lib_math.h"


typedef struct s_cylinder
{
    t_point center; // center point of the cylinder
    t_vec   axis; // axis vector of the cylinder (normalized)
    double  radius; // radius of the cylinder
    double  height; // height of the cylinder
} t_cylinder;





#endif
