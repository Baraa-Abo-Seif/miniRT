#ifndef OJ_OBJECT_H
#define OJ_OBJECT_H


#include "sphere/sphere.h"
#include "plane/plane.h"
#include "cylinder/cylinder.h"
#include "../../math/math.h"



typedef enum e_object_type
{
    SPHERE,
    PLANE,
    CYLINDER
} t_object_type;

typedef union u_object_data
{
    t_sphere    sphere;
    t_plane     plane;
    t_cylinder  cylinder;
}   t_object_data;


typedef struct s_object
{
    t_object_type      type; // object type
    t_color            color; // object color
    t_object_data      data; // object data (union of sphere, plane, cylinder, cone)
    struct s_object    *next; // pointer to the next object in the list
} t_object;









#endif
