#include "mini_rt.h"

t_tuples	*rotate_point_x(t_tuples *point, double radians)
{
	t_m4		*rotation_matrix;
	t_tuples	*rotated_point;

	rotation_matrix = rotate_x(radians);
	if (!rotation_matrix)
		return (NULL);
	rotated_point = matrix_times_tuple(rotation_matrix, point);
	free(rotation_matrix->col0);
	free(rotation_matrix->col1);
	free(rotation_matrix->col2);
	free(rotation_matrix->col3);
	free(rotation_matrix);
	return (rotated_point);
}

t_tuples	*rotate_point_y(t_tuples *point, double radians)
{
	t_m4		*rotation_matrix;
	t_tuples	*rotated_point;

	rotation_matrix = rotate_y(radians);
	if (!rotation_matrix)
		return (NULL);
	rotated_point = matrix_times_tuple(rotation_matrix, point);
	free(rotation_matrix->col0);
	free(rotation_matrix->col1);
	free(rotation_matrix->col2);
	free(rotation_matrix->col3);
	free(rotation_matrix);
	return (rotated_point);
}

t_tuples	*rotate_point_z(t_tuples *point, double radians)
{
	t_m4		*rotation_matrix;
	t_tuples	*rotated_point;

	rotation_matrix = rotate_z(radians);
	if (!rotation_matrix)
		return (NULL);
	rotated_point = matrix_times_tuple(rotation_matrix, point);
	free(rotation_matrix->col0);
	free(rotation_matrix->col1);
	free(rotation_matrix->col2);
	free(rotation_matrix->col3);
	free(rotation_matrix);
	return (rotated_point);
}

t_tuples	*shear_point(t_tuples *point, t_shear_params *params)
{
	t_m4		*shear_matrix;
	t_tuples	*sheared_point;

	shear_matrix = shearing(params);
	if (!shear_matrix)
		return (NULL);
	sheared_point = matrix_times_tuple(shear_matrix, point);
	free(shear_matrix->col0);
	free(shear_matrix->col1);
	free(shear_matrix->col2);
	free(shear_matrix->col3);
	free(shear_matrix);
	return (sheared_point);
}
