

#include "pattern.h"
#include <math.h>

t_color	checker_at(t_pattern *pattern, t_point point)
{
	long	cell;

	cell = (long)floor(point.x)
		+ (long)floor(point.y)
		+ (long)floor(point.z);
	if ((cell % 2 + 2) % 2 == 0)
		return (pattern->color_a);
	return (pattern->color_b);
}












