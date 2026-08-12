
#include "point.h"



t_vec	point_sub_point(t_point a, t_point b)
{
    t_vec result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;

    return result;
}






