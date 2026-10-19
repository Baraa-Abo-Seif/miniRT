/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 19:28:01 by bablo             #+#    #+#             */
/*   Updated: 2026/10/19 19:28:02 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"

void	check_normal(t_vec normal)
{
	double	length;

	length = vec_length(normal);
	if (fabs(length - 1.0) > 1e-6)
	{
		error_msg("Normal vector must be normalized");
		exit(EXIT_FAILURE);
	}
}
