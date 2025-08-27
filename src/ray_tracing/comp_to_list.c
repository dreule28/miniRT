#include "mini_rt.h"

void	set_dot_product(t_obj_node *curr)
{
	double	dot_product;

	dot_product = ftm_tup_dot(curr->comp.normalv, curr->comp.eyev);
	if (dot_product < 0)
	{
		curr->comp.inside = true;
		ftm_tup_negate(&curr->comp.normalv);
	}
	else
		curr->comp.inside = false;
}

void	set_epsilon_offset(t_obj_node *curr)
{
	t_tuples	epsilon_offset;

	ftm_tup_mult(&epsilon_offset, curr->comp.normalv, DBL_EPSILON);
	ftm_tup_add(&curr->comp.over_point, curr->comp.point, epsilon_offset);
}

bool	set_comp_to_obj(t_obj_node *curr, t_ray *ray)
{
	if (!curr->t)
		return (true);
	ray_position(&curr->comp.point, ray, curr->t[0]);
	if (!&curr->comp.point)
		return (false);
	ftm_tup_negate(&curr->comp.eyev);
	if (!&curr->comp.eyev)
		return (false);
	normal_at(&curr->comp.normalv, *curr, curr->comp.point);
	if (!&curr->comp.normalv)
		return (false);
	reflect(&curr->comp.reflectv, ray->direction, curr->comp.normalv);
	if (!&curr->comp.reflectv)
		return (false);
	set_dot_product(curr);
	set_epsilon_offset(curr);
	return (true);
}
