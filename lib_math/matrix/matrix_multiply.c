#include "matrix.h"

t_matrix	matrix_mul(t_matrix a, t_matrix b)
{
	t_matrix	result;
	int			row;
	int			col;
	int			k;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			result.m[row][col] = 0.0;
			k = 0;
			while (k < 4)
			{
				result.m[row][col] += a.m[row][k] * b.m[k][col];
				k++;
			}
			col++;
		}
		row++;
	}
	return (result);
}

