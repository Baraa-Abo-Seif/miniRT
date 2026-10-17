/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_display_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:54:21 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 16:54:24 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_display.h"

void	mlx_display_image(t_window *window, t_image *image)
{
	if (!window || !image|| !window->mlx|| !window->win|| !image->img)
		return ;
	mlx_put_image_to_window(window->mlx,window->win,image->img,0,0);
}
