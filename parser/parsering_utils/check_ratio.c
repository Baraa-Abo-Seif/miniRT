/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ratio.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 19:30:10 by bablo             #+#    #+#             */
/*   Updated: 2026/10/26 19:50:33 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"

bool	check_ratio(double ratio)
{
	if (ratio < 0.0 || ratio > 1.0)
	{
		error_msg("ratio must be between 0 and 1");
		return (false);
	}
	return (true);
}
