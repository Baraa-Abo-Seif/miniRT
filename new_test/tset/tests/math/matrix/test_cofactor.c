#include <stdio.h>
#include "../../../math/matrix/matrix.h"

int	main(void)
{
	t_matrix	matrix;
	double		minor;
	double		cofactor;

	matrix = matrix_identity();

	matrix.m[0][0] = -5;
	matrix.m[0][1] = 2;
	matrix.m[0][2] = 6;
	matrix.m[0][3] = -8;

	matrix.m[1][0] = 1;
	matrix.m[1][1] = -5;
	matrix.m[1][2] = 1;
	matrix.m[1][3] = 8;

	matrix.m[2][0] = 7;
	matrix.m[2][1] = 7;
	matrix.m[2][2] = -6;
	matrix.m[2][3] = -7;

	matrix.m[3][0] = 1;
	matrix.m[3][1] = -3;
	matrix.m[3][2] = 7;
	matrix.m[3][3] = 4;

	minor = matrix_minor(matrix, 0, 0);
	cofactor = matrix_cofactor(matrix, 0, 0);

	printf("Minor(0,0)    = %.2f\n", minor);
	printf("Cofactor(0,0) = %.2f\n\n", cofactor);

	minor = matrix_minor(matrix, 0, 1);
	cofactor = matrix_cofactor(matrix, 0, 1);

	printf("Minor(0,1)    = %.2f\n", minor);
	printf("Cofactor(0,1) = %.2f\n", cofactor);

	return (0);
}