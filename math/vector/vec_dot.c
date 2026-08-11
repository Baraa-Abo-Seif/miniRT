

#include "vector.h"


double vec_dot(t_vec a, t_vec b)
{
     double result;

    result = a.x * b.x + a.y * b.y + a.z * b.z;
    return (result);
}







