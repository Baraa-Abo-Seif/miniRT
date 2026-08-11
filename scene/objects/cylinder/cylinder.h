#ifndef CYLINDER_H
#define CYLINDER_H

#include "../../../math/point/point.h"
#include "../../../math/vector/vector.h"


typedef struct s_cylinder
{
    t_point center; // center point of the cylinder
    t_vec   axis; // axis vector of the cylinder (normalized)
    double  radius; // radius of the cylinder
    double  height; // height of the cylinder
} t_cylinder;





#endif
