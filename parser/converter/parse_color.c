
#include "converter.h"
#include "converter_internal.h"

t_color	parse_color(const char *str)
{
    t_color	color;

    color.r = ft_atof(str);
    skip_comma(&str);
    color.g = ft_atof(str);
    skip_comma(&str);
    color.b = ft_atof(str);
    normalize_color(&color);
    return (color);
}
