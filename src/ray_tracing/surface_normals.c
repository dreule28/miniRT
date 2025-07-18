#include "mini_rt.h"

void	free_tuple(t_tuples *tuple)
{
	if (tuple)
		free(tuple);
}

// t_tuples	*get_world_normal(t_obj_node *curr, t_m4 *inverse,
// 		t_tuples *obj_point)
// {
// 	t_m4		*transpose;
// 	t_tuples	*object_normal;
// 	t_tuples	*world_normal;
// 	t_tuples	*origin;

// 	origin = get_obj_origin(curr);
// 	transpose = ftm_transpose_matrix(inverse);
// 	object_normal = ftm_tup_subtract(obj_point, origin);
// 	world_normal = ftm_matrix_times_tuple(transpose, object_normal);
// 	if (!world_normal)
// 		return (NULL);
// 	world_normal->w = VECTOR;
// 	free_matrix_m4(transpose);
// 	free_tuple(object_normal);
// 	free_tuple(origin);
// 	return (world_normal);
// }

t_tuples	*normal_at(t_obj_node *curr, t_tuples *world_point)
{
	t_m4		*inverse;
	t_tuples	*object_point;
	t_tuples	*object_normal_vec;
	t_tuples	*world_normal;
	t_tuples	*normalized;
	t_m4		*transpose;

	inverse = ftm_m4_inversion(curr->matrix);
	if (!inverse)
		return (NULL);
	object_point = ftm_matrix_times_tuple(inverse, world_point);
	object_normal_vec = local_normal_at(curr, object_point);
	transpose = ftm_transpose_matrix(inverse);
	world_normal = ftm_matrix_times_tuple(transpose, object_normal_vec);
	if (!world_normal)
		return (NULL);
	world_normal->w = VECTOR;
	normalized = ftm_tup_norm(world_normal);
	free_tuple(object_point);
	free_tuple(object_normal_vec);
	free_tuple(world_normal);
	free_matrix_m4(inverse);
	free_matrix_m4(transpose);
	return (normalized);
}
