#include "mini_rt.h"

t_tuples	*local_normal_at(t_obj_node *curr, t_tuples *object_point)
{
	t_tuples	*local_normal_at;

	if (curr->type == SPHERE)
		local_normal_at = local_sphere(curr, object_point);
	if (curr->type == PLANE)
		local_normal_at = local_plane(curr, object_point);
	if (curr->type == CYLINDER)
		local_normal_at = local_cylinder(curr, object_point);
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

t_tuples	*local_cylinder(t_obj_node *curr, t_tuples *object_point)
{
	double	dist;

	dist = object_point->x * object_point->x + object_point->z
		* object_point->z;
	if (curr->data->cylinder->closed && dist < 1.0)
	{
		if (object_point->y >= curr->data->cylinder->maximum - EPSILON)
			return (init_vector(0, 1, 0));
		if (object_point->y <= curr->data->cylinder->minimum + EPSILON)
			return (init_vector(0, -1, 0));
	}
	return (init_vector(object_point->x, 0.0, object_point->z));
}
