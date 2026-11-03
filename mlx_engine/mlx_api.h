/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_api.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:11:09 by bablo             #+#    #+#             */
/*   Updated: 2026/11/03 17:23:50 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_API_H
# define MLX_API_H

#ifndef WINDOW_WIDTH
# define WINDOW_WIDTH 600
#endif

#ifndef WINDOW_HEIGHT
# define WINDOW_HEIGHT 600
#endif

#ifndef WINDOW_TITLE
# define WINDOW_TITLE "miniRT"
#endif

#include "Display/mlx_display.h"
#include "Events/mlx_event.h"
#include "Image/mlx_image.h"
#include "Pixel/mlx_pixel.h"
#include "Window/mlx_window.h"

#endif