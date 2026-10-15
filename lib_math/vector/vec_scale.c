

#include "vector.h"

t_vec vec_scale(t_vec a, double k)
{
    t_vec result;

    result.x = a.x * k;
    result.y = a.y * k;
    result.z = a.z * k;
    return (result);
}




