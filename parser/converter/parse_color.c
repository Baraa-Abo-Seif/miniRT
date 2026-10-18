/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 14:31:12 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/18 14:48:33 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"

t_color	parse_color(const char *str)
{
    t_color	color;

    color.r = parse_double(&str);
    skip_comma(&str);
    color.g = parse_double(&str);
    skip_comma(&str);
    color.b = parse_double(&str);
     if (color.r < 0 || color.r > 255
        || color.g < 0 || color.g > 255
        || color.b < 0 || color.b > 255)
    {
        error_msg("RGB values must be between 0 and 255");
        exit(EXIT_FAILURE);
    }
    normalize_color(&color);
    return (color);
}
