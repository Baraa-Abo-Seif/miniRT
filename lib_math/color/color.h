/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:42:12 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 14:42:13 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
#define COLOR_H

typedef struct s_color
{
    double	r;
    double	g;
    double	b;
}	t_color;

t_color	color_add(t_color a, t_color b);

t_color color_clamp_rgb(t_color color);

t_color	color_scale(t_color color, double k);

t_color	color_multiply(t_color a, t_color b);

double	color_clamp(double value);

int	color_to_hex(t_color color);

#endif