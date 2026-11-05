/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhoura <ralhoura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 18:33:06 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/05 17:23:06 by ralhoura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_H
# define PATTERN_H

# include "../lib_math/lib_math.h"

typedef enum e_pattern_type
{
	PATTERN_NONE,
	PATTERN_CHECKER
}					t_pattern_type;

typedef struct s_pattern
{
	t_pattern_type	type;
	t_color			color_a;
	t_color			color_b;
}					t_pattern;

void	radial_basis(t_vec axis, t_vec *radial_x, t_vec *radial_z);

t_color	sphere_checker_at(t_pattern *pattern, t_point point);
t_color	cylinder_checker_at_axis(t_pattern *pattern, t_point point,
			t_vec axis, double height);
t_color	plane_checker_at(t_pattern *pattern, t_point point,
			t_vec normal);
t_color	triangle_checker_at_normal(t_pattern *pattern,
			t_point point, t_vec normal);
t_color	paraboloid_checker_at_axis(t_pattern *pattern,
			t_point point, t_vec axis, double height);

#endif
