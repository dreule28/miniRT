#include "mini_rt.h"

t_m4	*ftm_translation(t_tuples *tuple)
{
	t_m4	*matrix;

	matrix = init_identity();
	if (!matrix)
		return (NULL);
	if (matrix->col3)
		free(matrix->col3);
	matrix->col3 = assign_m4_col(tuple->x, tuple->y, tuple->z, 1);
	return (matrix);
}

t_m4	*ftm_scaling(t_tuples *tuple)
{
	t_m4	*identity_matrix;

	identity_matrix = init_identity();
	if (!identity_matrix)
		return (NULL);
	identity_matrix->col0->x = identity_matrix->col0->x * tuple->x;
	identity_matrix->col1->y = identity_matrix->col1->y * tuple->y;
	identity_matrix->col2->z = identity_matrix->col2->z * tuple->z;
	return (identity_matrix);
}
