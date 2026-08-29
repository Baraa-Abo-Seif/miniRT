
#include "converter.h"
#include "converter_internal.h"



t_vec	parse_vector(const char *str)
{
    t_vec	vector;

    str = skip_spaces(str);
    vector.x = parse_double(&str);
    skip_comma(&str);
    vector.y = parse_double(&str);
    skip_comma(&str);
    vector.z = parse_double(&str);
    return (vector);
}
