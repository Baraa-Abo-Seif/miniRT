/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_build_basis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 17:32:42 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/29 17:32:43 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer_camera.h"

void	camera_build_basis(t_camera *camera)
{
	t_vec	world_up;

	if (!camera)
		return ;
	camera->forward = vec_normalize(camera->forward);
	world_up = (t_vec){0.0, 1.0, 0.0};
	if (fabs(camera->forward.y) > 0.999)
		world_up = (t_vec){1.0, 0.0, 0.0};
	camera->right = vec_normalize(vec_cross(world_up, camera->forward));
	camera->up = vec_normalize(vec_cross(camera->forward, camera->right));
}
