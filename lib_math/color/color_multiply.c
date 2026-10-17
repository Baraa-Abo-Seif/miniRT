/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_multiply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:41:56 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 14:41:59 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color_multiply(t_color a, t_color b)
{
	t_color multiply;

    multiply.r = a.r * b.r;
	multiply.g = a.g * b.g;
    multiply.b = a.b * b.b;

	return (multiply);
}


