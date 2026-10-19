/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ratio.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 19:30:10 by bablo             #+#    #+#             */
/*   Updated: 2026/10/19 19:30:11 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"

void	check_ratio(double ratio)
{
	if (ratio < 0.0 || ratio > 1.0)
	{
		error_msg("Ambient ratio must be between 0 and 1");
		exit(EXIT_FAILURE);
	}
}
