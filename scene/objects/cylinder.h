/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:18:00 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/03 19:58:06 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "../../lib_math/lib_math.h"

typedef struct s_cylinder
{
	t_point	center;
	t_vec	axis;
	double	radius;
	double	height;
}			t_cylinder;

#endif
