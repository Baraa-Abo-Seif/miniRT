
#include "color.h"



t_color	color_scale(t_color color, double k)
{
    t_color scale;

    scale.r = color.r * k;
    scale.g = color.g * k;
    scale.b = color.b * k;

    return (scale);
}



