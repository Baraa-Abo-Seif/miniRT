#include "matrix.h"

double	matrix_determinant_2x2(t_matrix matrix)
{
	return (matrix.m[0][0] * matrix.m[1][1]
		- matrix.m[0][1] * matrix.m[1][0]);
}

