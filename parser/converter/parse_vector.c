/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 14:28:36 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/18 14:28:37 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "converter.h"



t_vec	parse_vector(const char *str)
{
    t_vec	vector;

    vector.x = parse_double(&str);
    skip_comma(&str);
    vector.y = parse_double(&str);
    skip_comma(&str);
    vector.z = parse_double(&str);
    return (vector);
}
