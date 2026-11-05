/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:38:36 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/03 19:53:57 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IMAGE_H
# define MLX_IMAGE_H

# include "../../mlx/mlx.h"
# include "../../utils/utils.h"

typedef struct s_image
{
	void	*mlx;
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

t_image		*mlx_image_create(void *mlx, int width, int height);
int			mlx_image_data(t_image *image);
void		mlx_image_destroy(t_image *image);

#endif
