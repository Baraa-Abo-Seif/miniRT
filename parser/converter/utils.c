
#include "converter.h"

double	parse_double(const char **str)
{
	int		sign;
	double	result;

	*str = skip_spaces(*str);
	sign = parse_sign(str);
	result = parse_integer(str);
	result += parse_fraction(str);
	return (result * sign);
}


void	skip_comma(const char **str)
{
	if (**str == ',')
		(*str)++;
}

void	normalize_color(t_color *color)
{
	color->r /= 255.0;
	color->g /= 255.0;
	color->b /= 255.0;
}
