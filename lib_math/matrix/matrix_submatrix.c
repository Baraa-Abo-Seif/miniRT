#include "matrix.h"

t_matrix	matrix_submatrix(t_matrix matrix, int row, int col)
{
	t_matrix	result;
	int			src_row;
	int			src_col;
	int			dst_row;
	int			dst_col;

	dst_row = 0;
	src_row = 0;
	while (src_row < 4)
	{
		if (src_row == row)
		{
			src_row++;
			continue ;
		}
		dst_col = 0;
		src_col = 0;
		while (src_col < 4)
		{
			if (src_col == col)
			{
				src_col++;
				continue ;
			}
			result.m[dst_row][dst_col] = matrix.m[src_row][src_col];
			dst_col++;
			src_col++;
		}
		dst_row++;
		src_row++;
	}
	return (result);
}



