#ifndef LIGHT_H
#define LIGHT_H


#include "../../math/color/color.h"
#include "../../math/point/point.h"


typedef struct s_light
{
    t_point position;
    double  brightness;
    t_color color;
    struct s_light *next;
} t_light;










#endif

