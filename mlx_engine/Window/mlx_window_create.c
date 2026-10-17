/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 18:11:57 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 18:11:58 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_window.h"

t_window	*mlx_window_create(int width, int height, char *title)
{
	t_window	*window;

	window =ft_calloc(1, sizeof(t_window));
	if (!window)
	{
		error_msg("mlx_window_create: Memory allocation failed for window structure.");
		return (NULL);
	}
	window->width = width;
	window->height = height;
	window->mlx = mlx_init();
	if (!window->mlx)
	{
		error_msg("mlx_window_create: Failed to initialize MLX.");
		free(window);
		return (NULL);
	}
	window->win = mlx_new_window(window->mlx, width, height, title);
	if (!window->win)
	{
		error_msg("mlx_window_create: Failed to create MLX window.");
		mlx_window_destroy(window);
		return (NULL);
	}
	return (window);
}
