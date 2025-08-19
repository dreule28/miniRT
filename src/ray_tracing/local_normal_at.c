#include "mini_rt.h"

t_tuples	*local_normal_at(t_obj_node *curr, t_tuples *object_point)
{
	t_tuples	*local_normal_at;

	if (curr->type == SPHERE)
		local_normal_at = local_sphere(object_point);
	if (curr->type == PLANE)
		local_normal_at = local_plane();
	if (curr->type == CYLINDER)
		local_normal_at = local_cylinder(curr, object_point);
	if (curr->type == CUBE)
		local_normal_at = local_cube(object_point);
	return (local_normal_at);
}

t_tuples	*local_sphere(t_tuples *object_point)
{
	t_tuples	*origin;
	t_tuples	*normal;

	origin = init_point(0, 0, 0);
	normal = ftm_tup_subtract(object_point, origin);
	free_tuple(origin);
	return (normal);
}

t_tuples	*local_plane(void)
{
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

t_tuples	*local_cube(t_tuples *object_point)
{
	double	maxc;

	maxc = fmax(fmax(fabs(object_point->x), fabs(object_point->y)),
			fabs(object_point->z));
	if (maxc == fabs(object_point->x))
		return (init_vector(object_point->x, 0, 0));
	else if (maxc == fabs(object_point->y))
		return (init_vector(0, object_point->y, 0));
	return (init_vector(0, 0, object_point->z));
}
