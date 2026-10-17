/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 18:03:50 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 18:20:24 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_PIXEL_H
# define MLX_PIXEL_H
#include "../Image/mlx_image.h"


typedef struct s_image	t_image;

void	mlx_image_pixel_put(t_image *image, int x, int y, int color);

#endif
