#include "matrix.h"

double	matrix_cofactor(t_matrix matrix, int row, int col)
{
	double	minor;

	minor = matrix_minor(matrix, row, col);
	if ((row + col) % 2 != 0)
		minor = -minor;
	return (minor);
}