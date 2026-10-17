/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:43:02 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 15:00:23 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

# include "../vector/vector.h"
# include "../point/point.h"

typedef struct s_ray
{
    t_point origin;     // Starting point of the ray
    t_vec   direction;  // Normalized direction of travel
}t_ray;

t_point ray_at(t_ray ray, double t);

#endif
