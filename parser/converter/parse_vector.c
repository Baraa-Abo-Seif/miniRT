
#include "converter.h"
#include "converter_internal.h"



t_vec	parse_vector(const char *str)
{
    t_vec	vector;

    vector.x = ft_atof(str);
    skip_comma(&str);
    vector.y = ft_atof(str);
    skip_comma(&str);
    vector.z = ft_atof(str);
    return (vector);
}
