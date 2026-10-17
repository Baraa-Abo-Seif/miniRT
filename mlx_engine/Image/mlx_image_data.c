/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:36:14 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 17:37:37 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx_image.h"

int		mlx_image_data(t_image *image)
{
    if (!image || !image->img)
    {
        error_msg("mlx_image_data: Invalid image or image handle.");
        return (-1);
    }
    image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
        &image->line_length, &image->endian);
    if (!image->addr)
    {
        error_msg("mlx_image_data: Failed to get image data.");
        return (-1);
    }
    return (0);
}


