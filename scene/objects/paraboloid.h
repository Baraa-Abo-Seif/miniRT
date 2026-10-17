/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:18:16 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 16:18:17 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARABOLOID_H
# define PARABOLOID_H

# include "../../lib_math/lib_math.h"

typedef struct s_paraboloid
{
	t_point	vertex;
	t_vec	axis;
	double	radius;
	double	height;
}	t_paraboloid;

#endif