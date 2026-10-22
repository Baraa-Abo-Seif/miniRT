/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 14:31:37 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/22 18:45:36 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

#include "../../scene/scene.h"
#include "../../lib_math/lib_math.h"
#include "../parsering_utils/parsing_utils.h"


const char	*skip_spaces(const char *str);
int	parse_sign(const char **str);
double	parse_integer(const char **str);
double	parse_fraction(const char **str);
double		ft_atof(const char *str);

void	skip_comma(const char **str);
double parse_double(const char **str);

bool		parse_color(const char *str, t_color *color);

t_point	    parse_point(const char *str);

t_vec	parse_vector(const char *str);

#endif
