/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 19:28:01 by bablo             #+#    #+#             */
/*   Updated: 2026/10/20 16:35:15 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"

bool	check_normal(t_vec normal)
{
	double	length;

	length = vec_length(normal);
	if (fabs(length - 1.0) > 1e-6)
	{
		error_msg("Normal vector must be normalized");
		return (false);
	}
	return (true);
}
