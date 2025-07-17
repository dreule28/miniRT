#include "mini_rt.h"

void	free_tuple(t_tuples *tuple)
{
	if (tuple)
		free(tuple);
}

t_tuples	*get_world_normal(t_m4 *inverse, t_tuples *obj_point)
{
	t_m4		*transpose;
	t_tuples	*object_normal;
	t_tuples	*world_normal;
	t_tuples	*origin;

	origin = init_point(0, 0, 0);
	transpose = ftm_transpose_matrix(inverse);
	object_normal = ftm_tup_subtract(obj_point, origin);
	world_normal = ftm_matrix_times_tuple(transpose, object_normal);
	if (!world_normal)
		return (NULL);
	world_normal->w = 0;
	free_matrix_m4(transpose);
	free_tuple(object_normal);
	free_tuple(origin);
	return (world_normal);
}

t_tuples	*normal_at(t_obj_node *curr, t_tuples *world_point)
{
	t_m4		*inverse;
	t_tuples	*object_point;
	t_tuples	*world_normal;
	t_tuples	*normalized;

	inverse = ftm_m4_inversion(curr->matrix);
	if (!inverse)
		return (NULL);
	object_point = ftm_matrix_times_tuple(inverse, world_point);
	world_normal = get_world_normal(inverse, object_point);
	if (!world_normal)
		return (NULL);
	world_normal->w = VECTOR;
	normalized = ftm_tup_norm(world_normal);
	free_tuple(object_point);
	free_matrix_m4(inverse);
	free_tuple(world_normal);
	return (normalized);
}
