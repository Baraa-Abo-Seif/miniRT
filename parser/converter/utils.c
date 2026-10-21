/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 14:27:37 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/20 19:39:12 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"


void	skip_comma(const char **str)
{
	if (**str == ',')
		(*str)++;
}

double parse_double(const char **str)
{
    double value;

    *str = skip_spaces(*str);
    value = ft_atof(*str);
    while (**str && **str != ',')
        (*str)++;
    return (value);
}
