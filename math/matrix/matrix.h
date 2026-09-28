#ifndef MATRIX_H
#define MATRIX_H
# include "../point/point.h"

typedef struct s_matrix
{
	double	m[4][4];
}	t_matrix;

t_matrix	matrix_identity(void);
t_point		matrix_mul_point(t_matrix matrix, t_point point);
t_vec		matrix_mul_vec(t_matrix matrix, t_vec vec);
t_matrix	matrix_mul(t_matrix a, t_matrix b);
t_matrix	matrix_translation(double x, double y, double z);
t_matrix	matrix_scaling(double x, double y, double z);


t_matrix	matrix_rotation_x(double angle);
t_matrix	matrix_rotation_y(double angle);
t_matrix	matrix_rotation_z(double angle);

t_matrix matrix_submatrix(t_matrix matrix, int row, int col);

double	matrix_determinant_2x2(t_matrix matrix);
double	matrix_determinant_3x3(t_matrix matrix);
double	matrix_minor(t_matrix matrix, int row, int col);
double	matrix_cofactor(t_matrix matrix, int row, int col);



#endif