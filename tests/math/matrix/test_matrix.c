#include <stdio.h>
#include "../../../math/matrix/matrix.h"
#include <math.h>

static void	print_matrix(const char *name, t_matrix matrix)
{
	int	row;
	int	col;

	printf("%s:\n", name);
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			printf("%f ", matrix.m[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
}

static void	print_point(const char *name, t_point point)
{
	printf("%s = (%f, %f, %f)\n",
		name, point.x, point.y, point.z);
}

static void	print_vec(const char *name, t_vec vec)
{
	printf("%s = (%f, %f, %f)\n",
		name, vec.x, vec.y, vec.z);
}

static void	print_identity(t_matrix matrix)
{
	int	row;
	int	col;

	printf("Identity matrix:\n");
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			printf("%f ", matrix.m[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
}

int	main(void)
{
	t_matrix	identity;
	t_matrix	transform;
	t_point		point;
	t_point		result_point;
	t_vec		vec;
	t_vec		result_vec;

	t_matrix	a;
	t_matrix	b;
	t_matrix	result;

	printf("=== MATRIX IDENTITY ===\n");
	identity = matrix_identity();
	print_identity(identity);

	printf("\n=== IDENTITY * POINT ===\n");
	point = (t_point){1.0, 2.0, 3.0};
	result_point = matrix_mul_point(identity, point);
	print_point("point", point);
	print_point("result", result_point);

	printf("\n=== IDENTITY * VECTOR ===\n");
	vec = (t_vec){4.0, 5.0, 6.0};
	result_vec = matrix_mul_vec(identity, vec);
	print_vec("vector", vec);
	print_vec("result", result_vec);

	printf("\n=== TRANSLATION-LIKE MATRIX * POINT ===\n");
	transform = matrix_identity();
	transform.m[0][3] = 10.0;
	transform.m[1][3] = 20.0;
	transform.m[2][3] = 30.0;
	result_point = matrix_mul_point(transform, point);
	print_point("point", point);
	print_point("result", result_point);

	printf("\n=== TRANSLATION-LIKE MATRIX * VECTOR ===\n");
	result_vec = matrix_mul_vec(transform, vec);
	print_vec("vector", vec);
	print_vec("result", result_vec);

	printf("\n=== MATRIX * MATRIX ===\n");

	a = matrix_identity();
	b = matrix_identity();

	a.m[0][3] = 10.0;
	a.m[1][3] = 20.0;
	a.m[2][3] = 30.0;

	b.m[0][0] = 2.0;
	b.m[1][1] = 3.0;
	b.m[2][2] = 4.0;

	result = matrix_mul(a, b);

	print_matrix("A", a);
	print_matrix("B", b);
	print_matrix("A * B", result);

	transform = matrix_identity();
	transform.m[0][3] = 10.0;
	transform.m[1][3] = 20.0;
	transform.m[2][3] = 30.0;

	transform = matrix_translation(10.0, 20.0, 30.0);

	printf("\n=== TRANSLATION * POINT ===\n");
	transform = matrix_translation(10.0, 20.0, 30.0);
	result_point = matrix_mul_point(transform, point);
	print_point("point", point);
	print_point("result", result_point);

	printf("\n=== TRANSLATION * VECTOR ===\n");
	result_vec = matrix_mul_vec(transform, vec);
	print_vec("vector", vec);
	print_vec("result", result_vec);

	printf("\n=== SCALING * POINT ===\n");
	transform = matrix_scaling(2.0, 3.0, 4.0);
	result_point = matrix_mul_point(transform, point);
	print_point("point", point);
	print_point("result", result_point);

	printf("\n=== SCALING * VECTOR ===\n");
	result_vec = matrix_mul_vec(transform, vec);
	print_vec("vector", vec);
	print_vec("result", result_vec);
printf("\n=== ROTATION X ===\n");

printf("\n=== ROTATION X ===\n");

transform = matrix_rotation_x(acos(-1.0) / 2.0);

point = (t_point){0.0, 1.0, 0.0};
result_point = matrix_mul_point(transform, point);
print_point("point", point);
print_point("result", result_point);

vec = (t_vec){0.0, 1.0, 0.0};
result_vec = matrix_mul_vec(transform, vec);
print_vec("vector", vec);
print_vec("result", result_vec);

printf("\n=== ROTATION Y ===\n");

transform = matrix_rotation_y(acos(-1.0) / 2.0);

point = (t_point){1.0, 0.0, 0.0};
result_point = matrix_mul_point(transform, point);
print_point("point", point);
print_point("result", result_point);

vec = (t_vec){1.0, 0.0, 0.0};
result_vec = matrix_mul_vec(transform, vec);
print_vec("vector", vec);
print_vec("result", result_vec);


printf("\n=== ROTATION Z ===\n");

transform = matrix_rotation_z(acos(-1.0) / 2.0);

point = (t_point){1.0, 0.0, 0.0};
result_point = matrix_mul_point(transform, point);
print_point("point", point);
print_point("result", result_point);

vec = (t_vec){1.0, 0.0, 0.0};
result_vec = matrix_mul_vec(transform, vec);
print_vec("vector", vec);
print_vec("result", result_vec);


	return (0);
}
