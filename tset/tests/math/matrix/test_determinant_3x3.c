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

	matrix.m[1][0] = 0;
	matrix.m[1][1] = 4;
	matrix.m[1][2] = 5;

	matrix.m[2][0] = 1;
	matrix.m[2][1] = 0;
	matrix.m[2][2] = 6;

	result = matrix_determinant_3x3(matrix);

	printf("Matrix:\n");
	printf("[ %6.2f %6.2f %6.2f ]\n",
		matrix.m[0][0], matrix.m[0][1], matrix.m[0][2]);
	printf("[ %6.2f %6.2f %6.2f ]\n",
		matrix.m[1][0], matrix.m[1][1], matrix.m[1][2]);
	printf("[ %6.2f %6.2f %6.2f ]\n",
		matrix.m[2][0], matrix.m[2][1], matrix.m[2][2]);

	printf("\nDeterminant = %.2f\n", result);

	return (0);
}
