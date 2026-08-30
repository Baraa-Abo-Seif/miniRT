
#include "color.h"

int	color_to_hex(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = (int)(color_clamp(color.r) * 255.0);
	g = (int)(color_clamp(color.g) * 255.0);
	b = (int)(color_clamp(color.b) * 255.0);
	return ((255 << 24) | (r << 16) | (g << 8) | b);
}


