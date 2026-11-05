/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 17:40:38 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/03 17:35:30 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer_camera.h"

int	camera_init(t_camera *camera, int image_width, int image_height)
{
	if (!camera)
	{
		error_msg("camera_init: Camera pointer is NULL.");
		return (1);
	}
	camera_build_basis(camera);
	camera_compute_viewport(camera, image_width, image_height);
	camera_compute_pixel_delta(camera, image_width, image_height);
	return (0);
}
