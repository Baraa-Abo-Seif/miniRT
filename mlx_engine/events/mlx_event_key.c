/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:24:44 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 17:24:45 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_event.h"

int	mlx_event_key(int keycode, void *param)
{
	t_window	*window;

	window = (t_window *)param;
	if (keycode == KEY_ESC)
		return (mlx_event_close(window));
	return (0);
}
