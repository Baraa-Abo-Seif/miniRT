#ifndef RAY_H
#define RAY_H

#include "../../lib_math/lib_math.h"

typedef struct s_ray
{
    t_point origin;     // Starting point of the ray
    t_vec   direction;  // Normalized direction of travel
}t_ray;

t_point ray_at(t_ray ray, double t);

#endif
