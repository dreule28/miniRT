#include "mini_rt.h"

double	discri(t_ray *ray, t_sphere *sphere, double *a, double *b)
{
	t_tuples	*sphere_to_ray;
	double		discriminant;
	double		c;

	sphere_to_ray = ftm_tup_subtract(ray->origin, &sphere->pos);
	*a = ftm_tup_dot(ray->direction, ray->direction);
	*b = 2 * ftm_tup_dot(ray->direction, sphere_to_ray);
	c = ftm_tup_dot(sphere_to_ray, sphere_to_ray) -
		(sphere->radius * sphere->radius);
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
		return (NULL);
	t[0] = (-b - sqrtf(discriminant)) / (2 * a);
	t[1] = (-b + sqrtf(discriminant)) / (2 * a);
	return (t);
}

t_obj_list	*intersect_to_list(t_scene *scene)
{
	t_obj_node	*curr;
	t_ray	*ray;
	curr = scene->obj_list->head;
	while (curr)
	{
		if (curr->type == SPHERE)
		{
			ray = init_ray(&scene->camera.pos,
					&scene->camera.orientation_vector);
			if (!ray)
				return (NULL);
			curr->t = intersect_sphere(ray, curr->data->sphere);
			free(ray);
		}
		curr = curr->next;
	}
	return (scene->obj_list);
}

double	*hit_obj(t_scene *scene)
{
	t_obj_node	*curr;
	double		*old_hit;

	old_hit = ft_calloc(sizeof(double), 2);
	if(!old_hit)
		return(NULL);
	curr = scene->obj_list->head;
	old_hit = curr->t;
	while (curr)
	{	
		if (curr->t)
			if (old_hit[0] >= 0 && old_hit[0] > curr->t[0])
				old_hit = curr->t;
		curr = curr->next;
	}
	return (old_hit);
}
