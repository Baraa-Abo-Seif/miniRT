#include "matrix.h"

t_matrix	matrix_scaling(double x, double y, double z)
{
	t_matrix	matrix;

	matrix = matrix_identity();
	matrix.m[0][0] = x;
	matrix.m[1][1] = y;
	matrix.m[2][2] = z;
	return (matrix);
}


