#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

t_vec	vec_add(t_vec a, t_vec b);
t_vec	vec_sub(t_vec a, t_vec b);
t_vec	vec_scale(t_vec a, double k);

double	vec_length(t_vec v);
t_vec	vec_normalize(t_vec v);
double	vec_dot(t_vec a, t_vec b);

t_vec	vec_cross(t_vec a, t_vec b);
double	vec_distance(t_vec a, t_vec b);
t_vec	vec_reflect(t_vec incident, t_vec normal);

#endif

