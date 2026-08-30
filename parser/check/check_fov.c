#include "check.h"

void	check_fov(double fov)
{
	if (fov < 0.0 || fov > 180.0)
	{
		error_msg("FOV must be between 0.0 and 180.0");
		exit(EXIT_FAILURE);
	}
}