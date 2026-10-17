/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_clamp_rgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:41:27 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 14:41:29 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color_clamp_rgb(t_color color)
{
	color.r = color_clamp(color.r);
	color.g = color_clamp(color.g);
	color.b = color_clamp(color.b);
	return (color);
}

