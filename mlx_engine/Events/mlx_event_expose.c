/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_expose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:19:31 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 17:19:32 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_event.h"

int	mlx_event_expose(void *param)
{
	t_window	*window;

	window =(t_window *)param;
	if (!window || !window->image)
	{
		error_msg("mlx_event_expose: Invalid window or image.");
		return (0);
	}
	mlx_display_image(window, window->image);
	return (0);
}
