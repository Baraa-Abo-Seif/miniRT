/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_hit.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 18:59:42 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/26 18:59:43 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_HIT_H
# define CYLINDER_HIT_H

#include "../../scene/object.h"

typedef struct s_cap_context
{
	t_ray			ray;
	t_interval		interval;
	t_hit_record	*record;
}	t_cap_context;

void	fill_body_record(t_cylinder *cylinder,t_ray ray,
	t_quadratic_data *eq,t_hit_record *record);
bool	is_valid_body_root(t_cylinder *cylinder,t_ray ray,
	double root,t_interval interval);
bool	find_body_root(t_cylinder *cylinder,t_ray ray,
	t_quadratic_data *eq,t_interval interval);
void	compute_body_eq(t_quadratic_data *eq, t_cylinder *cylinder,
	t_ray ray);
bool	cylinder_hit(t_object *object, t_ray ray, t_interval interval,
	t_hit_record *record);

bool	find_cap_root(t_cap_context *ctx,t_point cap_center,
	t_vec cap_normal,double *root);
bool	check_single_cap(t_cylinder *cylinder,int side,t_cap_context *ctx);
bool	check_caps(t_cylinder *cylinder, t_cap_context *ctx);

#endif
