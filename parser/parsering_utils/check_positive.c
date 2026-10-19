/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_positive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 19:28:33 by bablo             #+#    #+#             */
/*   Updated: 2026/10/19 19:28:34 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"

void	check_positive(double value)
{
	if (value <= 0.0)
	{
		error_msg("Value must be greater than 0");
		exit(EXIT_FAILURE);
	}
}
