/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_hit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 18:04:08 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/26 18:12:13 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_HIT_H
# define PLANE_HIT_H

# include "../hit/hit_record.h"
#include "../../scene/object.h"

typedef struct s_plane_data
{
	double	denominator;
	double	t;
}	t_plane_data;

bool plane_hit(t_object *object ,t_ray ray,
    t_interval interval, t_hit_record *record);

#endif


