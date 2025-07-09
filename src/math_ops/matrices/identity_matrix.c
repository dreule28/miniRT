#include "mini_rt.h"

t_m4	*init_identity(void)
{
	t_m4	*new_matrix;

	new_matrix = init_m4();
	if (!new_matrix)
		return (NULL);
	new_matrix->col0 = assign_m4_col(1, 0, 0, 0);
	new_matrix->col1 = assign_m4_col(0, 1, 0, 0);
	new_matrix->col2 = assign_m4_col(0, 0, 1, 0);
	new_matrix->col3 = assign_m4_col(0, 0, 0, 1);
	return (new_matrix);
}
