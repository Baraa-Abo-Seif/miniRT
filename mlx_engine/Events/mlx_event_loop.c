/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:25:57 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 17:26:00 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx_event.h"

void	mlx_event_loop(t_window *window)
{
	if (!window || !window->mlx)
	{
		error_msg("mlx_event_loop: Invalid window.");
		return ;
	}
	mlx_loop(window->mlx);
}


