/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:33:13 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 17:33:14 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx_image.h"

t_image	*mlx_image_create(void *mlx, int width, int height)
{
    t_image	*image;

    image = ft_calloc(1, sizeof(t_image));
    if (!image)
    {
        error_msg("mlx_image_create: Memory allocation failed for image structure.");
        return (NULL);
    }
    image->mlx = mlx;
    image->width = width;
    image->height = height;
    image->img = mlx_new_image(mlx, width, height);
    if (!image->img)
    {
        error_msg("mlx_image_create: Failed to create MLX image.");
        mlx_image_destroy(image);
        return (NULL);
    }
    return (image); 
}

