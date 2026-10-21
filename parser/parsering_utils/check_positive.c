/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_positive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 19:28:33 by bablo             #+#    #+#             */
/*   Updated: 2026/10/20 16:31:24 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"

bool	check_positive(double value)
{
	if (value <= 0.0)
	{
		error_msg("Value must be greater than 0");
		return (false);
	}
	return (true);
}
