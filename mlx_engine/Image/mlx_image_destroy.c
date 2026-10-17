/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:36:20 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 17:36:21 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx_image.h"

void	mlx_image_destroy(t_image *image)
{
    if (!image)
        return ;
    if (image->img)
        mlx_destroy_image(image->mlx, image->img);
    free(image);
}

