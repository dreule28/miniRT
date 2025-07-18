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


t_obj_list	*intersect_to_list(t_scene *scene, t_ray *ray)
{
	t_obj_node	*curr;

	curr = scene->obj_list->head;
	while (curr)
	{
		if (!intersec_to_obj(scene, curr, ray))
			return (NULL);
		if (!set_comp_to_obj(curr, ray))
			return (NULL);
		curr = curr->next;
	}
	return (sort_obj_list(scene->obj_list));
}
