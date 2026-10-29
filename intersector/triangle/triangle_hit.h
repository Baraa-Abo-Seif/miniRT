/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_hit.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 19:56:37 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/26 19:56:38 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_HIT_H
# define TRIANGLE_HIT_H

# include "../scene/object.h"

typedef struct s_triangle_hit
{
	t_vec	edge_one;
	t_vec	edge_two;
	t_vec	to_ray;
	t_vec	cross_to_ray_edge_two;
	t_vec	cross_to_ray_edge_one;
	double	inverse_determinant;
	double	u;
	double	v;
	double	t;
}	t_triangle_hit;

bool	calculate_coordinates(t_ray ray, t_triangle_hit *data);
bool	calculate_determinant(t_ray ray, t_triangle_hit *data);
bool	triangle_hit(t_object *object, t_ray ray,
			t_interval interval, t_hit_record *record);
			
#endif