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

bool	set_comp_to_obj(t_obj_node *curr, t_ray *ray)
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
	set_dot_product(curr);
	set_epsilon_offset(curr);
	return (true);
}

double	*intersect_sphere(t_ray *ray, t_sphere *sphere)
{
	double	*t;
	double	a;
	double	b;
	double	discriminant;

	t = ft_calloc(sizeof(double), 2);
	if (!t)
		return (NULL);
	discriminant = discri(ray, sphere, &a, &b);
	if (discriminant < 0.0)
		return (free(t), NULL);
	t[0] = (-b - sqrtf(discriminant)) / (2 * a);
	t[1] = (-b + sqrtf(discriminant)) / (2 * a);
	return (t);
}

double *intersect_plane(t_ray *ray, t_plane *plane)
{
	double *t;
	double intersec;

	(void)plane;
	if(fabs(ray->direction->y) < DBL_EPSILON)
		return(NULL);
	intersec = -ray->origin->y / ray->direction->y;
	if (intersec <= 0)
        return(NULL);
	t = ft_calloc(sizeof(double), 2);
	if(!t)
		return(NULL);
	t[0] = intersec;
	t[1] = intersec;
	return(t);
}
