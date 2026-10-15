#include "matrix.h"

t_matrix	matrix_translation(double x, double y, double z)
{
	t_matrix	matrix;

	matrix = matrix_identity();
	matrix.m[0][3] = x;
	matrix.m[1][3] = y;
	matrix.m[2][3] = z;
	return (matrix);
}






