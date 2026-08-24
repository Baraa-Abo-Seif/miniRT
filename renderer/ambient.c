#include "renderer.h"



t_color	render_ambient(t_color object_color, t_ambient ambient)
{
	t_color	result;

	result = color_multiply(object_color, ambient.color);
	result = color_scale(result, ambient.ratio);
	return (result);
}


