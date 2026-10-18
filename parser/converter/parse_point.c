/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 14:28:34 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/18 14:28:35 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"

t_point	parse_point(const char *str)
{
    t_point	point;

    point.x = parse_double(&str);
    skip_comma(&str);
    point.y = parse_double(&str);
    skip_comma(&str);
    point.z = parse_double(&str);
    return (point);
}
