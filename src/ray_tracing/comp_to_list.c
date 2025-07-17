#include "mini_rt.h"

bool	set_comp_to_obj(t_obj_node *curr, t_ray *ray)
{
	double	dot_product;

	if (!curr->t)
		return (true);
	curr->comp->point = ray_position(ray, curr->t[0]);
	if (!curr->comp->point)
		return (false);
	curr->comp->eyev = ftm_tup_negate(ray->direction);
	if (!curr->comp->eyev)
		return (false);
	if (curr->type == SPHERE)
	{
		curr->comp->normalv = normal_at(curr, curr->comp->point);
		if (!curr->comp->normalv)
			return (false);
	}
	dot_product = ftm_tup_dot(curr->comp->normalv, curr->comp->eyev);
	if (dot_product < 0)
	{
		curr->comp->inside = true;
		curr->comp->normalv = ftm_tup_negate(curr->comp->normalv);
	}
	else
		curr->comp->inside = false;
	return (true);
}

double	*intersect_plane(t_ray *ray, t_plane *plane)
{
	(void)ray;
	(void)plane;
	return(NULL);
}
