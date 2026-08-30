

#include "check.h"

void	check_ratio(double ratio)
{
	if (ratio < 0.0 || ratio > 1.0)
	{
		error_msg("Ambient ratio must be between 0 and 1");
		exit(EXIT_FAILURE);
	}
}


