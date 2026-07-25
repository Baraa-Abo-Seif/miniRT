

#include "math.h"

t_vec vec_sub(t_vec a, t_vec b)
{
    t_vec result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return (result);
}



