#include "mini_rt.h"

double	*local_intersect(t_ray *ray)
{
	t_axis_params	axis;
	double			tmin;
	double			tmax;
	double			*t;

	check_axis(ray->origin->x, ray->direction->x, &axis.xtmax, &axis.xtmin);
	check_axis(ray->origin->y, ray->direction->y, &axis.ytmax, &axis.ytmin);
	check_axis(ray->origin->z, ray->direction->z, &axis.ztmax, &axis.ztmin);
	tmin = fmax(fmax(axis.xtmin, axis.ytmin), axis.ztmin);
	tmax = fmin(fmin(axis.xtmax, axis.ytmax), axis.ztmax);
	if (tmin > tmax)
		return (NULL);
	t = ft_calloc(sizeof(double), 2);
	if (!t)
		return (NULL);
	t[0] = tmin;
	t[1] = tmax;
	return (t);
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
