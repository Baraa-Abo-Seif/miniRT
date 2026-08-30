#include "color.h"

t_color	color_clamp_rgb(t_color color)
{
	color.r = color_clamp(color.r);
	color.g = color_clamp(color.g);
	color.b = color_clamp(color.b);
	return (color);
}

