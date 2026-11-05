/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhoura <ralhoura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:43:02 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/05 16:25:05 by ralhoura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "../point/point.h"
# include "../vector/vector.h"

typedef struct s_ray
{
	t_point	origin;
	t_vec	direction;
}	t_ray;

t_point	ray_at(t_ray ray, double t);

#endif
