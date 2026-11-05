/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhoura <ralhoura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:55:28 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/05 16:30:27 by ralhoura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_RECORD_H
# define HIT_RECORD_H

# include "../../lib_math/lib_math.h"
# include "../../scene/scene.h"
# include <stdbool.h>

typedef struct s_hit_record
{
	t_point	point;
	t_vec	normal;
	double	t;
	bool	front_face;
	void	*object;
}			t_hit_record;

typedef struct s_interval
{
	double	min;
	double	max;
}			t_interval;

typedef struct s_quadratic
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;
}			t_quadratic_data;

void	hit_record_set_face_normal(t_hit_record *record, t_ray ray,
			t_vec outward_normal);
bool	world_hit(t_scene *scene, t_ray ray, t_interval interval,
			t_hit_record *record);
bool	object_hit(t_object *object, t_ray ray, t_interval interval,
			t_hit_record *record);

#endif