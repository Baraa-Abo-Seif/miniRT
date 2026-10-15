#include "matrix.h"

t_vec	matrix_mul_vec(t_matrix matrix, t_vec vec)
{
	t_vec	result;

	result.x = matrix.m[0][0] * vec.x
		+ matrix.m[0][1] * vec.y
		+ matrix.m[0][2] * vec.z;
	result.y = matrix.m[1][0] * vec.x
		+ matrix.m[1][1] * vec.y
		+ matrix.m[1][2] * vec.z;
	result.z = matrix.m[2][0] * vec.x
		+ matrix.m[2][1] * vec.y
		+ matrix.m[2][2] * vec.z;
	return (result);
}






