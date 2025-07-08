#include "mini_rt.h"

double	discri(t_ray *ray, double *a, double *b)
{
	t_tuples	*sphere_to_ray;
	double		discriminant;
	double		c;
	
	sphere_to_ray = ftm_tup_subtract(ray->origin, init_point(0, 0, 0));
	*a = ftm_tup_dot(ray->direction, ray->direction);
	*b = 2 * ftm_tup_dot(ray->direction, sphere_to_ray);
	c = ftm_tup_dot(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = *b * *b - 4 * *a * c;
	printf("Discriminant: %f\n", discriminant);
	return (discriminant);
}
double	*intersects(t_ray *ray)
{
	double	*t;
	double	a;
	double	b;
	double	discriminant;
	
	t = ft_calloc(sizeof(double), 2);
	if (!t)
		return (NULL);
	discriminant = discri(ray, &a, &b);
	if (discriminant < 0.0)
		return (NULL);
	t[0] = (-b - sqrtf(discriminant)) / (2 * a);
	t[1] = (-b + sqrtf(discriminant)) / (2 * a);
	return(t);
}
