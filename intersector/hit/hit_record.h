#ifndef HIT_RECORD_H
# define HIT_RECORD_H

# include <stdbool.h>

# include "../../math/math.h"
# include "../../scene/ray/ray.h"

typedef struct s_hit_record
{
	t_point	point; // Point of intersection
	t_vec	normal; // Surface normal at the intersection point

	double	t; // Parameter t along the ray where the intersection occurs

	bool	front_face; // Indicates if the intersection is on the front face of the surface

	void	*object; // Pointer to the object that was hit (can be used for material properties, etc.)
}	t_hit_record;

void	hit_record_set_face_normal(t_hit_record *record,t_ray ray,t_vec outward_normal);



typedef struct s_quadratic
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;
}	t_quadratic_data;




#endif