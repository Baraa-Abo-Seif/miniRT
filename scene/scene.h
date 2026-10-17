/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:35:22 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 16:35:23 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCENE_H
#define SCENE_H

#include "./object.h"
#include "./camera.h"
#include "./ambient.h"
#include "./light.h"

typedef struct s_scene
{
    t_camera    camera;
    t_ambient   ambient;
    t_light     *lights;
    t_object    *objects;
    
}   t_scene;

#endif
