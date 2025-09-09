#include "mini_rt.h"

void	view_transformation(t_m4 *matrix, t_tuples from, t_tuples to,
		t_tuples up)
{
	t_tuples	forward;
	t_tuples	up_normelized;
	t_tuples	left;
	t_tuples	true_up;
	t_m4		orientation;

	ftm_tup_subtract(&forward, to, from);
	ftm_tup_norm(&forward, forward);
	ftm_tup_norm(&up_normelized, up);
	ftm_tup_cross(&left, forward, up_normelized);
	ftm_tup_cross(&true_up, left, forward);
	create_view_matrix(&orientation, left, forward, true_up);
	ftm_tup_negate(&from);
	ftm_matrix_mult(matrix, orientation, ftm_translation(from));
}

void	create_view_matrix(t_m4 *orientation, t_tuples left, t_tuples forward,
		t_tuples true_up)
{
	t_m4_col	col_values;

	col_values = (t_m4_col){left.x, true_up.x, -forward.x, 0.0};
	assign_m4_col(&orientation->col0, col_values);
	col_values = (t_m4_col){left.y, true_up.y, -forward.y, 0.0};
	assign_m4_col(&orientation->col1, col_values);
	col_values = (t_m4_col){left.z, true_up.z, -forward.z, 0.0};
	assign_m4_col(&orientation->col2, col_values);
	col_values = (t_m4_col){0.0, 0.0, 0.0, 1.0};
	assign_m4_col(&orientation->col3, col_values);
}
