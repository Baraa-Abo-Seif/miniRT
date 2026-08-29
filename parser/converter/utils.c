#include "converter.h"


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

double parse_double(const char **str)
{
    double value;

    *str = skip_spaces(*str);

    value = ft_atof(*str);

    while (**str && **str != ',')
        (*str)++;

    return (value);
}
