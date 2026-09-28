#include "matrix.h"
#include <math.h>

t_matrix	matrix_rotation_x(double angle)
{
	t_matrix	matrix;
	double		cos_angle;
	double		sin_angle;

	matrix = matrix_identity();
	cos_angle = cos(angle);
	sin_angle = sin(angle);
	matrix.m[1][1] = cos_angle;
	matrix.m[1][2] = -sin_angle;
	matrix.m[2][1] = sin_angle;
	matrix.m[2][2] = cos_angle;
	return (matrix);
}

t_matrix	matrix_rotation_y(double angle)
{
	t_matrix	matrix;
	double		cos_angle;
	double		sin_angle;

	matrix = matrix_identity();
	cos_angle = cos(angle);
	sin_angle = sin(angle);
	matrix.m[0][0] = cos_angle;
	matrix.m[0][2] = sin_angle;
	matrix.m[2][0] = -sin_angle;
	matrix.m[2][2] = cos_angle;
	return (matrix);
}


t_matrix	matrix_rotation_z(double angle)
{
	t_matrix	matrix;
	double		cos_angle;
	double		sin_angle;

	matrix = matrix_identity();
	cos_angle = cos(angle);
	sin_angle = sin(angle);
	matrix.m[0][0] = cos_angle;
	matrix.m[0][1] = -sin_angle;
	matrix.m[1][0] = sin_angle;
	matrix.m[1][1] = cos_angle;
	return (matrix);
}