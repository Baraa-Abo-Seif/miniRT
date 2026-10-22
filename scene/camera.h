/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:25:14 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/22 18:44:06 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
#define CAMERA_H

#include "../Libft/libft.h"

typedef struct s_camera
{
    t_point position;              // Camera position in world space
    t_vec   forward;               // Viewing direction (normalized)
    double  fov;                   // Field of view in degrees

    t_vec   right;                 // Camera local X axis
    t_vec   up;                    // Camera local Y axis

    double  viewport_width;        // Viewport width
    double  viewport_height;       // Viewport height

    t_point viewport_upper_left;   // Top-left corner of the viewport

    t_vec   pixel_delta_x;         // Horizontal distance between pixels
    t_vec   pixel_delta_y;         // Vertical distance between pixels

} t_camera;

#endif
