#include "mini_rt.h"

double	discri(t_ray *ray, t_sphere *sphere, double *a, double *b)
{
	t_tuples	*sphere_center;
	t_tuples	*sphere_to_ray;
	double		discriminant;
	double		c;

	sphere_center = copy_point(&sphere->pos);
	sphere_to_ray = ftm_tup_subtract(ray->origin, sphere_center);
	*a = ftm_tup_dot(ray->direction, ray->direction);
	*b = 2 * ftm_tup_dot(ray->direction, sphere_to_ray);
	c = ftm_tup_dot(sphere_to_ray, sphere_to_ray) - (sphere->radius
			* sphere->radius);
	discriminant = *b * *b - 4 * *a * c;
	free(sphere_to_ray);
	return (discriminant);
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
