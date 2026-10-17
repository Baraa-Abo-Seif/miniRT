/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:42:02 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 14:42:04 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"



t_color	color_scale(t_color color, double k)
{
    t_color scale;

    scale.r = color.r * k;
    scale.g = color.g * k;
    scale.b = color.b * k;

    return (scale);
}



