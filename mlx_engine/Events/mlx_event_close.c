/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:08:49 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 17:16:26 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_event.h"

int	mlx_event_close(void *param)
{
	t_window	*window;

	window = (t_window *)param;
	if (!window || !window->mlx)
	{
		error_msg("mlx_event_close: Invalid window or MLX instance.");
		return (0);	
	}
	mlx_loop_end(window->mlx);
	return (0);
}
