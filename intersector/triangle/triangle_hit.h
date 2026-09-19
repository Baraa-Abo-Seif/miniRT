#ifndef TRIANGLE_HIT_H
# define TRIANGLE_HIT_H

# include "../scene/objects/object.h"
# include "../scene/ray/ray.h"
# include "../hit/hit_record.h"
# include "../hit/interval.h"

typedef struct s_triangle_hit
{
	t_vec	edge_one;
	t_vec	edge_two;
	t_vec	to_ray;
	t_vec	cross_to_ray_edge_two;
	t_vec	cross_to_ray_edge_one;
	double	inverse_determinant;
	double	u;
	double	v;
	double	t;
}	t_triangle_hit;


bool	triangle_hit(t_object *object, t_ray ray,
			t_interval interval, t_hit_record *record);
void	init_triangle_data(t_object *object, t_ray ray,
				t_triangle_hit *data);
bool	calculate_determinant(t_ray ray,
				t_triangle_hit *data);
bool	calculate_coordinates(t_ray ray,
				t_triangle_hit *data);
bool	calculate_t(t_vec edge_two,
				t_triangle_hit *data,
				t_interval interval);
void	set_hit_record(t_object *object, t_ray ray,
				t_triangle_hit *data, t_hit_record *record);
				

#endif