/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:38:36 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 17:38:41 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IMAGE_H
# define MLX_IMAGE_H

# include "../../mlx/mlx.h"
# include "../../Libft/libft.h"
# include "../../utils/utils.h"



typedef struct s_image
{
	void	*mlx;			// MLX instance handle
	void	*img;			// MLX image handle
	char	*addr;			// Pointer to image buffer

	int		width;			// Image width in pixels
	int		height;			// Image height in pixels

	int		bits_per_pixel;	// Bits used to represent one pixel
	int		line_length;	// Number of bytes in one image row
	int		endian;			// Endianness of the image buffer
}	t_image;

t_image	*mlx_image_create(void *mlx, int width, int height);
int		mlx_image_data(t_image *image);
void	mlx_image_destroy(t_image *image);

#endif
