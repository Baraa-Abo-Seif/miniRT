/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_display.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:54:33 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 16:54:44 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DISPLAY_H
# define MLX_DISPLAY_H

# include "../../mlx/mlx.h"
#include "../Window/mlx_window.h"
#include "../Image/mlx_image.h"

typedef struct s_window	t_window;
typedef struct s_image	t_image;

void	mlx_display_image(t_window *window, t_image *image);

#endif
