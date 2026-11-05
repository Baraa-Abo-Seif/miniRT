/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:25:14 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/03 19:58:43 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "../lib_math/lib_math.h"

typedef struct s_camera
{
	t_point	position;
	t_vec	forward;
	double	fov;
	t_vec	right;
	t_vec	up;
	double	viewport_width;
	double	viewport_height;
	t_point	viewport_upper_left;
	t_vec	pixel_delta_x;
	t_vec	pixel_delta_y;

}			t_camera;

#endif
