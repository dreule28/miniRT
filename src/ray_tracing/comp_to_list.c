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
	t = ft_calloc(sizeof(double), 2);
	if(!t)
		return(NULL);
	t[0] = intersec;
	t[1] = intersec;
	return(t);
}
