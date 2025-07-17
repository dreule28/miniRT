#include "mini_rt.h"

t_m4	*view_transformation(t_tuples *from, t_tuples *to, t_tuples *up)
{
	t_tuples	*forward;
	t_tuples	*up_normelized;
	t_tuples	*left;
	t_tuples	*true_up;
	t_m4		*orientation;

	forward = ftm_tup_norm(ftm_tup_subtract(to, from));
	up_normelized = ftm_tup_norm(up);
	left = ftm_tup_cross(forward, up_normelized);
	true_up = ftm_tup_cross(left, forward);
	orientation = create_view_matrix(left, forward, true_up);
	from = ftm_tup_negate(from);
	free_tuple(forward);
	free_tuple(up_normelized);
	free_tuple(left);
	free_tuple(true_up);
	return (ftm_matrix_mult(orientation, ftm_translation(from)));
}

t_m4	*create_view_matrix(t_tuples *left, t_tuples *forward,
	t_tuples *true_up)
{
	t_m4	*orientation;

	orientation = init_m4();
	orientation->col0 = assign_m4_col(left->x, true_up->x, -forward->x, 0.0);
	orientation->col1 = assign_m4_col(left->y, true_up->y, -forward->y, 0.0);
	orientation->col2 = assign_m4_col(left->z, true_up->z, -forward->z, 0.0);
	orientation->col3 = assign_m4_col(0.0, 0.0, 0.0, 1.0);
	return (orientation);
}
