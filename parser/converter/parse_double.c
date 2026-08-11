

#include "converter.h"
#include "converter_internal.h"

const char	*skip_spaces(const char *str)
{
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    return (str);
}

int	parse_sign(const char **str)
{
    int	sign;

    sign = 1;
    if (**str == '-')
    {
        sign = -1;
        (*str)++;
    }
    else if (**str == '+')
        (*str)++;
    return (sign);
}


double	parse_integer(const char **str)
{
    double	result;

    result = 0;
    while (**str >= '0' && **str <= '9')
    {
        result = result * 10 + (**str - '0');
        (*str)++;
    }
    return (result);
}

double	parse_fraction(const char **str)
{
    double	result;
    double	decimal;

    result = 0;
    decimal = 0.1;
    if (**str == '.')
    {
        (*str)++;
        while (**str >= '0' && **str <= '9')
        {
            result += (**str - '0') * decimal;
            decimal *= 0.1;
            (*str)++;
        }
    }
    return (result);
}

double	ft_atof(const char *str)
{
    int		sign;
    double	result;

    str = skip_spaces(str);
    sign = parse_sign(&str);
    result = parse_integer(&str);
    result += parse_fraction(&str);
    return (result * sign);
}





