/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:54:24 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 16:24:07 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIP_MATH_H
# define LIP_MATH_H

#ifndef EPSILON
# define EPSILON 1e-6
#endif

#ifndef SHADOW_EPSILON
# define SHADOW_EPSILON 0.0001
#endif

#ifndef RAY_T_MIN
# define RAY_T_MIN 0.001
#endif

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif


# include "./vector/vector.h"
# include "./point/point.h"
# include "./color/color.h"
# include "./ray/ray.h"

#endif


