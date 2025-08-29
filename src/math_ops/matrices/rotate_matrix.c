#include "mini_rt.h"

t_m4	ftm_rotate_x(double radians)
{
	t_m4	matrix;

	assign_m4_col(&matrix.col0, 1, 0, 0, 0);
	assign_m4_col(&matrix.col1, 0, cos(radians), sin(radians), 0);
	assign_m4_col(&matrix.col2, 0, -sin(radians), cos(radians), 0);
	assign_m4_col(&matrix.col3, 0, 0, 0, 1);
	return (matrix);
}

t_m4	ftm_rotate_y(double radians)
{
	t_m4	matrix;

	assign_m4_col(&matrix.col0, cos(radians), 0, -sin(radians), 0);
	assign_m4_col(&matrix.col1, 0, 1, 0, 0);
	assign_m4_col(&matrix.col2, sin(radians), 0, cos(radians), 0);
	assign_m4_col(&matrix.col3, 0, 0, 0, 1);
	return (matrix);
}

t_m4	ftm_rotate_z(double radians)
{
	t_m4	matrix;

	assign_m4_col(&matrix.col0, cos(radians), sin(radians), 0, 0);
	assign_m4_col(&matrix.col1, -sin(radians), cos(radians), 0, 0);
	assign_m4_col(&matrix.col2, 0, 0, 1, 0);
	assign_m4_col(&matrix.col3, 0, 0, 0, 1);
	return (matrix);
}

double	radians(double degree)
{
	return (degree * M_PI / 180.0);
}
