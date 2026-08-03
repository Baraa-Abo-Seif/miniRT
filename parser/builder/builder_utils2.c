#include "builder_internal.h"

t_point	parse_point(char *str)
{
    t_point	point;
    char	**parts;

    parts = ft_split(str, ',');
    point.x = ft_atof(parts[0]);
    point.y = ft_atof(parts[1]);
    point.z = ft_atof(parts[2]);
    free_string_array(parts);
    return (point);
}

t_vec	parse_vec(char *str)
{
    t_vec	vec;
    char	**parts;

    parts = ft_split(str, ',');
    vec.x = ft_atof(parts[0]);
    vec.y = ft_atof(parts[1]);
    vec.z = ft_atof(parts[2]);
    free_string_array(parts);
    return (vec);
}

t_color	parse_color(char *str)
{
    t_color	color;
    char	**parts;

    parts = ft_split(str, ',');
    color.r = ft_atoi(parts[0]);
    color.g = ft_atoi(parts[1]);
    color.b = ft_atoi(parts[2]);
    free_string_array(parts);
    return (color);
}
