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

void	check_cylinder_height(double *t ,t_ray *ray, t_cylinder *cylinder)
{
	double y0;
	double y1;
	double tmp;

	if(t[0] > t[1])
	{
		tmp = t[0];
		t[0] = t[1];
		t[1] = tmp;
	}
	y0 = ray->origin->y + t[0] * ray->direction->y;
	if(cylinder->minimum < y0 && y0 < cylinder->maximum)

	if(cylinder->minimum < y1 && y1 < cylinder->maximum)

}

double	*intersect_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	double a;
	double b;
	double c;
	double *t;
	double discri;

	t = ft_calloc(sizeof(double), 2);
	if(!t)
		return(NULL);
	a = ray->direction->x * ray->direction->x + ray->direction->z  * ray->direction->z;
	b = (2 * ray->origin->x * ray->direction->x) + (2 * ray->origin->z  * ray->direction->z);
	c = ray->origin->x * ray->origin->x + ray->origin->z  * ray->origin->z - 1;
	discri = b * b - 4 * a * c;
	if(discri < 0.0)
		return(NULL);
	t[0] = (-b - sqrtf(discri)) / (2 * a);
	t[1] = (-b + sqrtf(discri)) / (2 * a);
	check_cylinder_height(t, ray, cylinder);
	return(t);
}
