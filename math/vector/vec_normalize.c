


#include "vector.h"


t_vec vec_normalize(t_vec v)
{
    double length;
    t_vec result;

    length = vec_length(v);
    if (length == 0)
    {
        result.x = 0;
        result.y = 0;
        result.z = 0;
        return (result);
    }
    result.x = v.x / length;
    result.y = v.y / length;
    result.z = v.z / length;
    return (result);
}




