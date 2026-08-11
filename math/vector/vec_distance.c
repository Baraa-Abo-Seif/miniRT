

#include "vector.h"

double vec_distance(t_vec a, t_vec b)
{
    t_vec victor;
    double distance;

    victor = vec_sub(a, b);
    distance = vec_length(victor);
    return (distance);
}







