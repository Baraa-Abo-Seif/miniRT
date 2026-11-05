/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_api.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhoura <ralhoura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:11:09 by bablo             #+#    #+#             */
/*   Updated: 2026/11/05 18:08:50 by ralhoura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_API_H
# define MLX_API_H

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 600
# endif

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 600
# endif

# ifndef WINDOW_TITLE
#  define WINDOW_TITLE "miniRT"
# endif

# include "display/mlx_display.h"
# include "events/mlx_event.h"
# include "image/mlx_image.h"
# include "pixel/mlx_pixel.h"
# include "window/mlx_window.h"

#endif