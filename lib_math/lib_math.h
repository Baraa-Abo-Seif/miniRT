/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:54:24 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/02 18:31:41 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MATH_H
# define LIB_MATH_H

# ifndef EPSILON
#  define EPSILON 1e-6
# endif

# ifndef SHADOW_EPSILON
#  define SHADOW_EPSILON 0.0001
# endif

# ifndef RAY_T_MIN
#  define RAY_T_MIN 0.001
# endif

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# ifndef DEFAULT_BUMP_INTENSITY
#  define DEFAULT_BUMP_INTENSITY 1.0
# endif

# ifndef BUMP_PLANE_SCALE
#  define BUMP_PLANE_SCALE 0.25
# endif

# ifndef SPHERE_CHECKER_SIZE
#  define SPHERE_CHECKER_SIZE 8
# endif

# ifndef CYL_U_SIZE
#  define CYL_U_SIZE 8
# endif

# ifndef CYL_V_SIZE
#  define CYL_V_SIZE 2
# endif

# ifndef PLANE_SCALE
#  define PLANE_SCALE 0.5
# endif

# ifndef TRI_SCALE
#  define TRI_SCALE 2
# endif

# ifndef PARA_SCALE
#  define PARA_SCALE 5
# endif

# include "./color/color.h"
# include "./point/point.h"
# include "./ray/ray.h"
# include "./vector/vector.h"

#endif
