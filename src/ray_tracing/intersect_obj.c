#include "mini_rt.h"

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

double	*intersect_plane(t_ray *ray, t_plane *plane)
{
	double	*t;
	double	intersec;

	(void)plane;
	if (fabs(ray->direction->y) < DBL_EPSILON)
		return (NULL);
	intersec = -ray->origin->y / ray->direction->y;
	if (intersec <= 0)
		return (NULL);
	t = ft_calloc(sizeof(double), 2);
	if (!t)
		return (NULL);
	t[0] = intersec;
	t[1] = intersec;
	return (t);
}
