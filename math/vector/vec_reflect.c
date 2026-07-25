
#include "math.h"


t_vec vec_reflect(t_vec incident, t_vec normal)
{
    double d;
    t_vec projection;

    d = vec_dot(incident, normal);
    projection = vec_scale(normal, 2 * d);
    return (vec_sub(incident, projection));
}



