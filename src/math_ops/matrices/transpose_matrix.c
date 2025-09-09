#include "mini_rt.h"

void	ftm_transpose_matrix(t_m4 *new_matrix, t_m4 old_matrix)
{
	assign_m4_col(&new_matrix->col0, old_matrix.col0.x, old_matrix.col1.x,
		old_matrix.col2.x, old_matrix.col3.x);
	assign_m4_col(&new_matrix->col1, old_matrix.col0.y, old_matrix.col1.y,
		old_matrix.col2.y, old_matrix.col3.y);
	assign_m4_col(&new_matrix->col2, old_matrix.col0.z, old_matrix.col1.z,
		old_matrix.col2.z, old_matrix.col3.z);
	assign_m4_col(&new_matrix->col3, old_matrix.col0.w, old_matrix.col1.w,
		old_matrix.col2.w, old_matrix.col3.w);
}
