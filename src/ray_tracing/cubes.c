#include "mini_rt.h"

bool	local_intersect(t_obj_node *node, t_ray ray)
{
	t_axis_params	axis;
	double			tmin;
	double			tmax;

	check_axis(ray.origin.x, ray.direction.x, &axis.xtmax, &axis.xtmin);
	check_axis(ray.origin.y, ray.direction.y, &axis.ytmax, &axis.ytmin);
	check_axis(ray.origin.z, ray.direction.z, &axis.ztmax, &axis.ztmin);
	tmin = fmax(fmax(axis.xtmin, axis.ytmin), axis.ztmin);
	tmax = fmin(fmin(axis.xtmax, axis.ytmax), axis.ztmax);
	if (tmin > tmax)
	{
		node->has_intersection = false;
		return (false);
	}
	node->t[0] = tmin;
	node->t[1] = tmax;
	node->has_intersection = true;
	return (true);
}

void	check_axis(double origin, double direction, double *tmax, double *tmin)
{
	double	tmin_numerator;
	double	tmax_numerator;
	double	temp;

	tmin_numerator = (-1 - origin);
	tmax_numerator = (1 - origin);
	if (fabs(direction) >= EPSILON)
	{
		*tmin = tmin_numerator / direction;
		*tmax = tmax_numerator / direction;
	}
	else
	{
		*tmin = tmin_numerator * INFINITY;
		*tmax = tmax_numerator * INFINITY;
	}
	if (*tmin > *tmax)
	{
		temp = *tmax;
		*tmax = *tmin;
		*tmin = temp;
	}
}
