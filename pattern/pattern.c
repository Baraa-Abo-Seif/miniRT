#include "pattern.h"
#include <math.h>

# define SPHERE_CHECKER_SIZE 8

static double	clamp_unit(double value)
{
	if (value < -1.0)
		return (-1.0);
	if (value > 1.0)
		return (1.0);
	return (value);
}

t_color	sphere_checker_at(t_pattern *pattern, t_point point)
{
	double	radius;
	double	latitude;
	double	longitude;
	long	latitude_cell;
	long	longitude_cell;
	long	cell;

	radius = sqrt(point.x * point.x + point.y * point.y
		+ point.z * point.z);
	if (radius < EPSILON)
		return (pattern->color_a);
	latitude = acos(clamp_unit(point.y / radius)) / acos(-1.0)
		* SPHERE_CHECKER_SIZE;
	longitude = (atan2(point.x, point.z) + acos(-1.0))
		/ (2.0 * acos(-1.0)) * SPHERE_CHECKER_SIZE;
	latitude_cell = (long)floor(latitude);
	longitude_cell = (long)floor(longitude);
	if (latitude_cell >= SPHERE_CHECKER_SIZE)
		latitude_cell = SPHERE_CHECKER_SIZE - 1;
	if (longitude_cell >= SPHERE_CHECKER_SIZE)
		longitude_cell = 0;
	cell = latitude_cell + longitude_cell;
	if ((cell % 2 + 2) % 2 == 0)
		return (pattern->color_a);
	return (pattern->color_b);
}

t_color	pattern_at(t_pattern *pattern, t_point point)
{
	if (pattern->type == PATTERN_CHECKER)
		return (checker_at(pattern, point));
	return (pattern->color_a);
}









