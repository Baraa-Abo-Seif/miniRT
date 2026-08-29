#include "converter.h"
#include "converter_internal.h"

t_point	parse_point(const char *str)
{
    t_point	point;

    str = skip_spaces(str);
    point.x = parse_double(&str);
    skip_comma(&str);
    point.y = parse_double(&str);
    skip_comma(&str);
    point.z = parse_double(&str);
    return (point);
}




