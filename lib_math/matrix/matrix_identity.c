#include "matrix.h"

t_matrix	matrix_identity(void)
{
	t_matrix	matrix;
	int			row;
	int			col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (row == col)
				matrix.m[row][col] = 1.0;
			else
				matrix.m[row][col] = 0.0;
			col++;
		}
		row++;
	}
	return (matrix);
}
