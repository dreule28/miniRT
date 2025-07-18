#include "mini_rt.h"

t_tuples	*local_normal_at(t_obj_node *curr, t_tuples *object_point)
{
	t_tuples	*local_normal_at;

	if (curr->type == SPHERE)
		local_normal_at = local_sphere(curr, object_point);
	if (curr->type == PLANE)
		local_normal_at = local_plane(curr, object_point);
	return (local_normal_at);
}

t_tuples	*local_sphere(t_obj_node *curr, t_tuples *object_point)
{
	t_tuples	*origin;
	t_tuples	*normal;

	(void)curr;
	origin = init_point(0, 0, 0);
	normal = ftm_tup_subtract(object_point, origin);
	free_tuple(origin);
	return (normal);
}

t_tuples	*local_plane(t_obj_node *curr, t_tuples *object_point)
{
	(void)curr;
	(void)object_point;
	return (init_vector(0, 1, 0));
}
