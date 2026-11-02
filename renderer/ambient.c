/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 18:12:16 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/29 18:12:17 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

t_color	render_ambient(t_color object_color, t_ambient ambient)
{
	t_color	result;

	result = color_multiply(object_color, ambient.color);
	result = color_scale(result, ambient.ratio);
	return (result);
}
