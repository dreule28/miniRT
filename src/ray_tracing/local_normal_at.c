#include "mini_rt.h"

void	local_normal_at(t_tuples *local_normal_at, t_obj_node curr,
				t_tuples object_point)
{
	if (curr.type == SPHERE)
		local_sphere(local_normal_at, object_point);
	if (curr.type == PLANE)
		local_plane(local_normal_at);
	if (curr.type == CYLINDER)
		local_cylinder(local_normal_at, curr, object_point);
	if (curr.type == CUBE)
		local_cube(local_normal_at, object_point);
	if (curr.type == TRIANGLE)
		*local_normal_at = curr.data->triangle->normal;
	if ( curr.type == CONE)
		local_cone(local_normal_at,curr, object_point);
}

void	local_sphere(t_tuples *normal, t_tuples object_point)
{
	t_tuples	origin;

	init_point(&origin, 0, 0, 0);
	ftm_tup_subtract(normal, object_point, origin);
}

void	local_plane(t_tuples *local_normal_at)
{
	return (init_vector(local_normal_at, 0, 1, 0));
}

void	local_cylinder(t_tuples *normal, t_obj_node curr, t_tuples object_point)
{
	double	dist;

	dist = object_point.x * object_point.x + object_point.z
		* object_point.z;
	if (curr.data->cylinder->closed && dist < 1.0)
	{
		if (object_point.y >= curr.data->cylinder->maximum - EPSILON)
		{
			init_vector(normal, 0, 1, 0);
			return ;
		}
		if (object_point.y <= curr.data->cylinder->minimum + EPSILON)
		{
			init_vector(normal, 0, -1, 0);
			return ;
		}
	}
	init_vector(normal, object_point.x, 0, object_point.z);
	return ;
}

void	local_cube(t_tuples *local_normal_at, t_tuples object_point)
{
	double	maxc;

	maxc = fmax(fmax(fabs(object_point.x), fabs(object_point.y)),
			fabs(object_point.z));
	if (maxc == fabs(object_point.x))
	{
		init_vector(local_normal_at, object_point.x, 0, 0);
		return ;
	}
	else if (maxc == fabs(object_point.y))
	{
		init_vector(local_normal_at, 0, object_point.y, 0);
		return ;
	}
	init_vector(local_normal_at, 0, 0, object_point.z);
	return ;
}
