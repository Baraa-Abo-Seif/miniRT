#include "builder_internal.h"

const char	*skip_spaces_and_sign(const char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	return (str);
}

int	is_valid_number(const char *str)
{
	int	dot;
	int	digit;

	dot = 0;
	digit = 0;
	str = skip_spaces_and_sign(str);
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str == '.')
			dot++;
		else if (*str >= '0' && *str <= '9')
			digit++;
		else
			return (0);
		str++;
	}
	if (dot > 1 || digit == 0)
		return (0);
	return (1);
}

double	parse_integer(const char **str)
{
	double	res;

	res = 0.0;
	while (**str >= '0' && **str <= '9')
		res = res * 10 + *((*str)++) - '0';
	return (res);
}

double	parse_decimal(const char **str, double res)
{
	double	dec;

	dec = 1.0;
	if (**str == '.')
	{
		(*str)++;
		while (**str >= '0' && **str <= '9')
		{
			dec /= 10;
			res += (**str - '0') * dec;
			(*str)++;
		}
	}
	return (res);
}

double	ft_atof(const char *str)
{
	int		sign;
	double	res;

	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!is_valid_number(str))
		return (0.0);
	res = parse_integer(&str);
	res = parse_decimal(&str, res);
	if (res >= 2.0 || res <= -2.0)
	{
		write(2, "Error : value out of range\n", 27);
		exit(1);
	}
	return (res * sign);
}
