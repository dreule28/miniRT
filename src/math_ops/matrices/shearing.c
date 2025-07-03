#include "mini_rt.h"

t_m4	*shear_x(double xy, double xz)
{
	t_m4	*matrix;

	matrix = init_m4();
	if (!matrix)
		return (NULL);
	matrix->col0 = assign_m4_col(1, 0, 0, 0);
	matrix->col1 = assign_m4_col(xy, 1, 0, 0);
	matrix->col2 = assign_m4_col(xz, 0, 1, 0);
	matrix->col3 = assign_m4_col(1, 0, 0, 1);
	return (matrix);
}

t_m4	*shear_y(double yx, double yz)
{
	t_m4	*matrix;

	matrix = init_m4();
	if (!matrix)
		return (NULL);
	matrix->col0 = assign_m4_col(1, yx, 0, 0);
	matrix->col1 = assign_m4_col(0, 1, 0, 0);
	matrix->col2 = assign_m4_col(0, yz, 1, 0);
	matrix->col3 = assign_m4_col(0, 0, 0, 1);
	return (matrix);
}

t_m4	*shear_z(double zx, double zy)
{
	t_m4	*matrix;

	matrix = init_m4();
	if (!matrix)
		return (NULL);
	matrix->col0 = assign_m4_col(1, 0, zx, 0);
	matrix->col1 = assign_m4_col(0, 1, zy, 0);
	matrix->col2 = assign_m4_col(0, 0, 1, 0);
	matrix->col3 = assign_m4_col(0, 0, 0, 1);
	return (matrix);
}

t_m4	*shearing(t_shear_params *params)
{
	t_m4	*matrix;

	matrix = init_m4();
	if (!matrix)
		return (NULL);
	matrix->col0 = assign_m4_col(1, params->yx, params->zx, 0);
	matrix->col1 = assign_m4_col(params->xy, 1, params->zy, 0);
	matrix->col2 = assign_m4_col(params->xz, params->yz, 1, 0);
	matrix->col3 = assign_m4_col(0, 0, 0, 1);
	return (matrix);
}
