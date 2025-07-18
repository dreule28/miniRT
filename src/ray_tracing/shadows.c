#include "mini_rt.h"

t_ray	*get_shadow_ray(t_scene *scene, t_tuples *point, double *distance)
{
	t_tuples	*distance_v;
	t_tuples	*direction;
	t_ray		*ray;

	distance_v = ftm_tup_subtract(&scene->light_list->head->pos, point);
	*distance = magnitude_vector(distance_v);
	direction = ftm_tup_norm(distance_v);
	ray = init_ray(copy_point(point), direction);
	free_tuple(distance_v);
	return (ray);
}

double	*get_transformed_intersection(t_obj_node *curr, t_ray *ray)
{
	t_ray	*transformed_ray;
	t_m4	*inv;
	double	*t;

	transformed_ray = ray;
	if (curr->matrix)
	{
		inv = ftm_m4_inversion(curr->matrix);
		if (inv)
		{
			transformed_ray = transform_ray(ray, inv);
			free_matrix_m4(inv);
		}
	}
	t = intersect_shape(curr, transformed_ray);
	if (transformed_ray != ray)
		free_ray(transformed_ray);
	return (t);
}

bool	check_shadow_intersection(double *t, double distance, double *min_t)
{
	if (t && t[0] >= 0 && t[0] < distance && t[0] < *min_t)
	{
		*min_t = t[0];
		return (true);
	}
	return (false);
}

bool	check_objects_for_shadow(t_scene *scene, t_ray *ray, double distance)
{
	t_obj_node	*curr;
	double		*t;
	double		min_t;
	bool		shadowed;

	shadowed = false;
	min_t = INFINITY;
	curr = scene->obj_list->head;
	while (curr)
	{
		if (curr->type == SPHERE)
		{
			t = get_transformed_intersection(curr, ray);
			if (check_shadow_intersection(t, distance, &min_t))
				shadowed = true;
			if (t)
				free(t);
		}
		curr = curr->next;
	}
	return (shadowed);
}

bool	is_shadowed(t_scene *scene, t_tuples *point)
{
	t_ray	*ray;
	double	distance;
	bool	shadowed;

	ray = get_shadow_ray(scene, point, &distance);
	if (!ray)
		return (false);
	shadowed = check_objects_for_shadow(scene, ray, distance);
	free_ray(ray);
	return (shadowed);
}
