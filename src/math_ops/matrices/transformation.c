#include "mini_rt.h"

t_m4	*ftm_translation(t_m4 *matrix, t_tuples *tuple)
{
	matrix->col3 = assign_m4_col(matrix->col3->x + tuple->x, matrix->col3->y
			+ tuple->y, matrix->col3->z + tuple->z, 1);
	return (matrix);
}

t_m4	*ftm_scaling(t_m4 *matrix, t_tuples *tuple)
{
	matrix->col0->x = matrix->col0->x * tuple->x;
	matrix->col1->y = matrix->col1->y * tuple->y;
	matrix->col2->z = matrix->col2->z * tuple->z;
	return (matrix);
}
