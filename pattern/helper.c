/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhoura <ralhoura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 18:28:25 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/05 17:08:03 by ralhoura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

void	radial_basis(t_vec axis, t_vec *radial_x, t_vec *radial_z)
{
	t_vec	reference;

	if (fabs(axis.x) < EPSILON && fabs(axis.z) < EPSILON)
	{
		*radial_x = (t_vec){1.0, 0.0, 0.0};
		*radial_z = (t_vec){0.0, 0.0, 1.0};
		return ;
	}
	if (fabs(axis.y) < 0.9)
		reference = (t_vec){0.0, 1.0, 0.0};
	else
		reference = (t_vec){0.0, 0.0, 1.0};
	*radial_x = vec_normalize(vec_cross(reference, axis));
	*radial_z = vec_normalize(vec_cross(axis, *radial_x));
}
