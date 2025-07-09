#include "mini_rt.h"

t_m4	*ftm_transpose_matrix(t_m4 *old_matrix)
{
	t_m4	*new_matrix;

	if (!old_matrix || !old_matrix->col0 || !old_matrix->col1
		|| !old_matrix->col2 || !old_matrix->col3)
		return (NULL);
	new_matrix = init_m4();
	if (!new_matrix)
		return (NULL);
	new_matrix->col0 = assign_m4_col(old_matrix->col0->x, old_matrix->col1->x,
			old_matrix->col2->x, old_matrix->col3->x);
	new_matrix->col1 = assign_m4_col(old_matrix->col0->y, old_matrix->col1->y,
			old_matrix->col2->y, old_matrix->col3->y);
	new_matrix->col2 = assign_m4_col(old_matrix->col0->z, old_matrix->col1->z,
			old_matrix->col2->z, old_matrix->col3->z);
	new_matrix->col3 = assign_m4_col(old_matrix->col0->w,
			old_matrix->col1->w, old_matrix->col2->w,
			old_matrix->col3->w);
	return (new_matrix);
}
