
#include "converter.h"

t_color	parse_color(const char *str)
{
    t_color	color;

    color.r = parse_double(&str) ;
    skip_comma(&str);
    color.g = parse_double(&str) ;
    skip_comma(&str);
    color.b = parse_double(&str) ;
    normalize_color(&color);
    return (color);
}
