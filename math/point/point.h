#ifndef POINT_H
#define POINT_H

#include "../vector/vector.h"

typedef struct s_point
{
    double x;
    double y;
    double z;
} t_point;


t_point	point_add_vec(t_point point, t_vec vec);
t_point	point_sub_vec(t_point point, t_vec vec);
t_vec	point_sub_point(t_point a, t_point b);



#endif
