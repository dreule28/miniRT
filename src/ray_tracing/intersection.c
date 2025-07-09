#include "mini_rt.h"

double	discri(t_ray *ray, t_sphere *sphere, double *a, double *b)
{
	t_tuples	*sphere_to_ray;
	double		discriminant;
	double		c;

	sphere_to_ray = ftm_tup_subtract(ray->origin, init_point(0, 0, 0));
	*a = ftm_tup_dot(ray->direction, ray->direction);
	*b = 2 * ftm_tup_dot(ray->direction, sphere_to_ray);
	c = ftm_tup_dot(sphere_to_ray, sphere_to_ray) - (sphere->radius * sphere->radius);
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

t_obj_list	*intersect_to_list(t_scene *scene)
{
	t_obj_node	*curr;
	t_ray		*ray;
	t_m4		*inv;

	curr = scene->obj_list->head;
	while (curr)
	{
		if (curr->type == SPHERE)
		{
			ray = init_ray(init_point(scene->camera.pos.x, scene->camera.pos.y, scene->camera.pos.z),
					init_vector(scene->camera.orientation_vector.x, scene->camera.orientation_vector.y, scene->camera.orientation_vector.z));
			if (!ray)
				return (NULL);
			set_transform(curr->data->sphere,
				ftm_translation(init_identity(), init_vector(5, 0, 0)));
			inv = ftm_m4_inversion(curr->data->sphere->matrix);
			ray = transform_ray(ray, inv);
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
