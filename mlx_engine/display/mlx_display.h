/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_display.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhoura <ralhoura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:54:33 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/05 18:09:08 by ralhoura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DISPLAY_H
# define MLX_DISPLAY_H

# include "../../mlx/mlx.h"
# include "../image/mlx_image.h"
# include "../window/mlx_window.h"

void	mlx_display_image(t_window *window, t_image *image);

#endif
