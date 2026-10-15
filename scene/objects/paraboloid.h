#ifndef PARABOLOID_H
# define PARABOLOID_H

# include "../../lib_math/lib_math.h"

typedef struct s_paraboloid
{
	t_point	vertex;
	t_vec	axis;
	double	radius;
	double	height;
}	t_paraboloid;

#endif