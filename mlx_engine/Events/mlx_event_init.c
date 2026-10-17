/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:23:05 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 17:23:06 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_event.h"


void	mlx_event_init(t_window *window)
{
	if (!window || !window->mlx || !window->win)
	{
		error_msg("mlx_event_init: Invalid window.");
		return ;
	}

	mlx_hook(window->win, EVENT_DESTROY_NOTIFY, 0,
		(int (*)())mlx_event_close, window);
	mlx_hook(window->win, EVENT_KEY_PRESS, KEY_PRESS_MASK,
		(int (*)())mlx_event_key, window);
	mlx_expose_hook(window->win, mlx_event_expose, window);
}
