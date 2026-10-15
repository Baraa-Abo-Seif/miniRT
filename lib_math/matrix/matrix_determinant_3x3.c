#include "matrix.h"

double	matrix_determinant_3x3(t_matrix matrix)
{
	t_matrix	sub;
	double		det;

	sub = matrix_submatrix(matrix, 0, 0);
	det = matrix.m[0][0] * matrix_determinant_2x2(sub);

	sub = matrix_submatrix(matrix, 0, 1);
	det -= matrix.m[0][1] * matrix_determinant_2x2(sub);

	sub = matrix_submatrix(matrix, 0, 2);
	det += matrix.m[0][2] * matrix_determinant_2x2(sub);

	return (det);
}
