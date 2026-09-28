#include "matrix.h"

double	matrix_minor(t_matrix matrix, int row, int col)
{
	t_matrix	submatrix;

	submatrix = matrix_submatrix(matrix, row, col);
	return (matrix_determinant_3x3(submatrix));
}
