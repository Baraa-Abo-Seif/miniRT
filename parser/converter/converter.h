#ifndef CONVERTER_H
# define CONVERTER_H

# include "../../scene/scene.h"


double		ft_atof(const char *str);
t_color		parse_color(const char *str);
t_point	    parse_point(const char *str);
t_vec	parse_vector(const char *str);


#endif

