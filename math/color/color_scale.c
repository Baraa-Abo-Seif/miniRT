
#include "color.h"



t_color	color_scale(t_color color, double k)
{
    return (t_color){color.r * k, color.g * k, color.b * k};
}



