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

t_obj_list	*intersect_to_list(t_scene *scene, t_ray *ray)
{
	t_obj_node	*curr;

	curr = scene->obj_list->head;
	while (curr)
	{
		if (!set_intersection_to_obj(scene, curr, ray))
			return (NULL);
		curr = curr->next;
	}
	return (scene->obj_list);
}

double	*hit_obj(t_scene *scene)
{
	t_obj_node	*curr;
	double		*closest_hit;
	double		min_t;

	closest_hit = NULL;
	min_t = INFINITY;
	curr = scene->obj_list->head;
	while (curr)
	{
		if (curr->t && curr->t[0] >= 0 && curr->t[0] < min_t)
		{
			min_t = curr->t[0];
			closest_hit = curr->t;
		}
		curr = curr->next;
	}
	return (closest_hit);
}
