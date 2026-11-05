/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_camera.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 18:01:38 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/29 18:01:39 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_CAMERA_H
# define RENDERER_CAMERA_H

# include "../../utils/utils.h"

int		camera_init(t_camera *camera, int image_width, int image_height);
void	camera_build_basis(t_camera *camera);
void	camera_compute_viewport(t_camera *camera, int image_width,
			int image_height);
void	camera_compute_pixel_delta(t_camera *camera, int image_width,
			int image_height);
t_ray	camera_generate_ray(t_camera *camera, int x, int y);

#endif
