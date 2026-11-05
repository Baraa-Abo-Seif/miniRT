/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid_hit.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhoura <ralhoura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:25:14 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/05 16:31:41 by ralhoura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARABOLOID_HIT_H
# define PARABOLOID_HIT_H

# include "../hit/hit_record.h"

typedef struct s_paraboloid_data
{
	t_paraboloid	*paraboloid;
	t_ray			ray;
	t_interval		interval;
	double			coefficient;
}					t_paraboloid_data;

bool	valid_root(t_paraboloid *paraboloid, t_ray ray,
			t_interval interval, double root);
t_vec	to_local(t_vec value, t_vec axis, t_vec side,
			t_vec other_side);
void	calculate_equation_paraboloid(t_paraboloid_data data,
			t_quadratic_data *equation);
bool	paraboloid_find_root(t_paraboloid_data data, double *root);
bool	paraboloid_hit(t_object *object, t_ray ray,
			t_interval interval, t_hit_record *record);

#endif