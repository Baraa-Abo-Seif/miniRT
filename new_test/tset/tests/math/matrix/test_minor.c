#include <stdio.h>
#include "../../../math/matrix/matrix.h"

int	main(void)
{
	t_matrix	matrix;
	double		result;

	matrix = matrix_identity();

	matrix.m[0][0] = 1;
	matrix.m[0][1] = 2;
	matrix.m[0][2] = 3;
	matrix.m[0][3] = 4;

	matrix.m[1][0] = 5;
	matrix.m[1][1] = 6;
	matrix.m[1][2] = 7;
	matrix.m[1][3] = 8;

	matrix.m[2][0] = 9;
	matrix.m[2][1] = 10;
	matrix.m[2][2] = 11;
	matrix.m[2][3] = 12;

	matrix.m[3][0] = 13;
	matrix.m[3][1] = 14;
	matrix.m[3][2] = 15;
	matrix.m[3][3] = 16;

	result = matrix_minor(matrix, 1, 2);

	printf("Minor(row=1, col=2) = %.2f\n", result);

	return (0);
}
