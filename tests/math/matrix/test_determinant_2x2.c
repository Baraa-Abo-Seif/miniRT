#include <stdio.h>
#include "../../../math/matrix/matrix.h"

int	main(void)
{
	t_matrix	matrix;
	double		result;

	matrix = matrix_identity();

	matrix.m[0][0] = 1;
	matrix.m[0][1] = 5;
	matrix.m[1][0] = -3;
	matrix.m[1][1] = 2;

	result = matrix_determinant_2x2(matrix);

	printf("Matrix:\n");
	printf("[ %6.2f %6.2f ]\n", matrix.m[0][0], matrix.m[0][1]);
	printf("[ %6.2f %6.2f ]\n", matrix.m[1][0], matrix.m[1][1]);

	printf("\nDeterminant = %.2f\n", result);

	return (0);
}


