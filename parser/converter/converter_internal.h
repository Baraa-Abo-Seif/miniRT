#ifndef CONVERTER_INTERNAL_H
#define CONVERTER_INTERNAL_H


double	parse_integer(const char **str);
const char	*skip_spaces(const char *str);
int	parse_sign(const char **str);
double	parse_fraction(const char **str);
double	parse_double(const char **str);
void	skip_comma(const char **str);
void	normalize_color(t_color *color);

//////////



#endif
