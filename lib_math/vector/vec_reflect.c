/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_reflect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:56:34 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 14:56:35 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	vec_reflect(t_vec incident, t_vec normal)
{
	double	d;
	t_vec	projection;

	d = vec_dot(incident, normal);
	projection = vec_scale(normal, 2 * d);
	return (vec_sub(incident, projection));
}

