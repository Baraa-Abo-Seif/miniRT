
#include "converter.h"
#include "converter_internal.h"
#include "../../math/color/color.h"
#include "../check/check.h"

t_color	parse_color(const char *str)
{
    t_color	color;

    str = skip_spaces(str);
    color.r = parse_double(&str);
    skip_comma(&str);
    color.g = parse_double(&str);
    skip_comma(&str);
    color.b = parse_double(&str);
    check_color(color);
    normalize_color(&color);
    return (color);
}
