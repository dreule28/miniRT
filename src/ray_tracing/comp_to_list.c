#include "mini_rt.h"

void	set_dot_product(t_obj_node *curr)
{
	double	dot_product;

	dot_product = ftm_tup_dot(curr->comp->normalv, curr->comp->eyev);
	if (dot_product < 0)
	{
		curr->comp->inside = true;
		curr->comp->normalv = ftm_tup_negate(curr->comp->normalv);
	}
	else
		curr->comp->inside = false;
}

void	set_epsilon_offset(t_obj_node *curr)
{
	t_tuples	*epsilon_offset;

	epsilon_offset = ftm_tup_mult(curr->comp->normalv, DBL_EPSILON);
	curr->comp->over_point = ftm_tup_add(curr->comp->point, epsilon_offset);
	free(epsilon_offset);
}

void	set_refraction(t_obj_node *curr, t_obj_list *intersections)
{
	if (intersections)
		calculate_refractive(intersections, curr);
	else
	{
		curr->comp->n1 = 1.0;
		curr->comp->n2 = 1.0;
	}
}

void	set_epsilon_offset_under(t_obj_node *curr)
{
	t_tuples	*eps_offset;

	eps_offset = ftm_tup_mult(curr->comp->normalv, DBL_EPSILON);
	curr->comp->under_point = ftm_tup_subtract(curr->comp->point, eps_offset);
	free(eps_offset);
}

bool	set_comp_to_obj(t_obj_node *curr, t_ray *ray, t_obj_list *intersections)
{
	if (!curr->t)
		return (true);
	curr->comp->point = ray_position(ray, curr->t[0]);
	if (!curr->comp->point)
		return (false);
	curr->comp->eyev = ftm_tup_negate(ray->direction);
	if (!curr->comp->eyev)
		return (false);
	if (curr->type == SPHERE || curr->type == PLANE)
	{
		curr->comp->normalv = normal_at(curr, curr->comp->point);
		if (!curr->comp->normalv)
			return (false);
	}
	curr->comp->reflectv = reflect(ray->direction, curr->comp->normalv);
	if (!curr->comp->reflectv)
		return (false);
	set_dot_product(curr);
	set_epsilon_offset(curr);
	set_epsilon_offset_under(curr);
	set_refraction(curr, intersections);
	return (true);
}
