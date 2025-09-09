#include "mini_rt.h"

void	init_identity(t_m4 *new_matrix)
{
	t_m4_col	col_values;

	col_values = (t_m4_col){1, 0, 0, 0};
	assign_m4_col(&new_matrix->col0, col_values);
	col_values = (t_m4_col){0, 1, 0, 0};
	assign_m4_col(&new_matrix->col1, col_values);
	col_values = (t_m4_col){0, 0, 1, 0};
	assign_m4_col(&new_matrix->col2, col_values);
	col_values = (t_m4_col){0, 0, 0, 1};
	assign_m4_col(&new_matrix->col3, col_values);
}
