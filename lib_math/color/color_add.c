#include "color.h"


t_color	color_add(t_color a, t_color b)
{
    t_color add;
    
    add.r = a.r + b.r;
    add.g = a.g + b.g;
    add.b = a.b + b.b;

    return (add);
}
