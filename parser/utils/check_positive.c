#include "check.h"

void	check_positive(double value)
{
	if (value <= 0.0)
	{
		error_msg("Value must be greater than 0");
		exit(EXIT_FAILURE);
	}
}
