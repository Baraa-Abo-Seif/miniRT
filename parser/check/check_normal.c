#include <math.h>
#include "check.h"

void	check_normal(t_vec normal)
{
	double	length;

	length = vec_length(normal);
	if (fabs(length - 1.0) > 1e-6)
	{
		error_msg("Normal vector must be normalized");
		exit(EXIT_FAILURE);
	}
}

