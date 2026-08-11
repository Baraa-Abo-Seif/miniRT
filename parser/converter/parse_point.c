#include "converter.h"
#include "converter_internal.h"

t_point	parse_point(const char *str)
{
    t_point	point;

    point.x = ft_atof(str);
    skip_comma(&str);
    point.y = ft_atof(str);
    skip_comma(&str);
    point.z = ft_atof(str);
    return (point);
}




