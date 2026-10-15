#include "matrix.h"

t_point	matrix_mul_point(t_matrix matrix, t_point point)
{
	t_point	result;

	result.x = matrix.m[0][0] * point.x
		+ matrix.m[0][1] * point.y
		+ matrix.m[0][2] * point.z
		+ matrix.m[0][3];
	result.y = matrix.m[1][0] * point.x
		+ matrix.m[1][1] * point.y
		+ matrix.m[1][2] * point.z
		+ matrix.m[1][3];
	result.z = matrix.m[2][0] * point.x
		+ matrix.m[2][1] * point.y
		+ matrix.m[2][2] * point.z
		+ matrix.m[2][3];
	return (result);
}



