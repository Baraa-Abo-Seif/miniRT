/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_hit.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:24:28 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/26 18:12:13 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_HIT_H
#define SPHERE_HIT_H

#include "../../scene/object.h"

#include "../hit/hit_record.h"


void	fill_body_record_sphere(t_object *object,t_ray ray,
    t_quadratic_data *eq, t_hit_record *record);
bool	find_root(t_quadratic_data *eq,t_interval interval);

void	calculate_equation(t_sphere *sphere,t_ray ray,t_quadratic_data *eq);

bool	sphere_hit(t_object *object, t_ray ray, t_interval interval,
     t_hit_record *record);

#endif
