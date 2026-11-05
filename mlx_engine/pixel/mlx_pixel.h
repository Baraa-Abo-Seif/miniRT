/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhoura <ralhoura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 18:03:50 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/05 18:09:12 by ralhoura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_PIXEL_H
# define MLX_PIXEL_H
# include "../image/mlx_image.h"

void	mlx_image_pixel_put(t_image *image, int x, int y, int color);

#endif
