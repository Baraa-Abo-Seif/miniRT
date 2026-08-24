#include "color.h"


t_color	color_add(t_color a, t_color b)
{
    return (t_color){a.r + b.r, a.g + b.g, a.b + b.b};
}
