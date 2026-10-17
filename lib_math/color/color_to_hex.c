/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:42:06 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 14:42:08 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	color_to_hex(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = (int)(color_clamp(color.r) * 255.0);
	g = (int)(color_clamp(color.g) * 255.0);
	b = (int)(color_clamp(color.b) * 255.0);
	return ((r << 16) | (g << 8) | b);
}


