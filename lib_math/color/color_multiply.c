#include "color.h"

t_color	color_multiply(t_color a, t_color b)
{
	t_color multiply;

    multiply.r = a.r * b.r;
	multiply.g = a.g * b.g;
    multiply.b = a.b * b.b;

	return (multiply);
}


