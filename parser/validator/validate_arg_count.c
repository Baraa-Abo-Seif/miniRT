/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arg_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:39:58 by bablo             #+#    #+#             */
/*   Updated: 2026/10/19 18:39:59 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"

bool	validate_arg_count(t_token *tokens)
{
	t_token	*current;
	size_t	actual_count;

	current = tokens;
	while (current)
	{
		actual_count = 0;
		while (current->args && current->args[actual_count])
			actual_count++;
		if (!is_valid_arg_count(current->type, actual_count))
			return (error_msg_line(current->line_number,
					"Invalid number of arguments."));
		current = current->next;
	}
	return (true);
}
