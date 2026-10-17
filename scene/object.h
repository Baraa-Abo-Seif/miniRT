/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:33:01 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 16:33:02 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OJ_OBJECT_H
#define OJ_OBJECT_H


#include "./objects/sphere.h"
#include "./objects/plane.h"
#include "./objects/cylinder.h"
#include "./objects/triangle.h"
#include "./objects/paraboloid.h"
#include "../lib_math/lib_math.h"
#include "../pattern/pattern.h"
#include "../texture/texture.h"



typedef enum e_object_type
{
    SPHERE,
    PLANE,
    CYLINDER,
    TRIANGLE,
    PARABOLOID
} t_object_type;

typedef union u_object_data
{
    t_sphere    sphere;
    t_plane     plane;
    t_cylinder  cylinder;
    t_triangle  triangle;
    t_paraboloid paraboloid;
}   t_object_data;


typedef struct s_object
{
    t_object_type      type; // object type
    t_color            color; // object color
    double shininess;
    t_object_data      data; // object data (union of sphere, plane, cylinder, cone)
    struct s_object    *next; // pointer to the next object in the list
    t_pattern            pattern;
    t_bump_map         bump_map;
    t_color_texture     color_texture;

} t_object;









#endif
