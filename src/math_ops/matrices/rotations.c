#include "mini_rt.h"

t_m4	*rotate_x(double radians)
{
	t_m4	*matrix;

	matrix = init_m4();
	if (!matrix)
		return (NULL);
	matrix->col0 = assign_m4_col(1, 0, 0, 0);
	matrix->col1 = assign_m4_col(0, cos(radians), sin(radians), 0);
	matrix->col2 = assign_m4_col(0, -sin(radians), cos(radians), 0);
	matrix->col3 = assign_m4_col(0, 0, 0, 1);
	return (matrix);
}

t_m4	*rotate_y(double radians)
{
	t_m4	*matrix;

	matrix = init_m4();
	if (!matrix)
		return (NULL);
	matrix->col0 = assign_m4_col(cos(radians), 0, -sin(radians), 0);
	matrix->col1 = assign_m4_col(0, 1, 0, 0);
	matrix->col2 = assign_m4_col(sin(radians), 0, cos(radians), 0);
	matrix->col3 = assign_m4_col(0, 0, 0, 1);
	return (matrix);
}

t_m4	*rotate_z(double radians)
{
	t_m4	*matrix;

	matrix = init_m4();
	if (!matrix)
		return (NULL);
	matrix->col0 = assign_m4_col(cos(radians), sin(radians), 0, 0);
	matrix->col1 = assign_m4_col(-sin(radians), cos(radians), 0, 0);
	matrix->col2 = assign_m4_col(0, 0, 1, 0);
	matrix->col3 = assign_m4_col(0, 0, 0, 1);
	return (matrix);
}

double	radians(double degree)
{
	return (degree * M_PI / 180.0);
}
