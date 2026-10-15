
#include "point.h"


t_point	point_sub_vec(t_point point, t_vec vec)
{
    t_point result;

    result.x = point.x - vec.x;
    result.y = point.y - vec.y;
    result.z = point.z - vec.z;

    return result;
}
