#include "mini_rt.h"

void	get_shadow_ray(t_ray *ray, t_tuples point, double *distance,
			t_light curr)
{
	t_tuples	distance_v;
	t_tuples	direction;

	ftm_tup_subtract(&distance_v, curr.pos, point);
	*distance = magnitude_vector(distance_v);
	ftm_tup_norm(&direction, distance_v);
	init_ray(ray, point, direction);
}

bool	get_transformed_intersection(t_obj_node *curr, t_ray ray)
{
	t_ray	transformed_ray;
	t_m4	inv;

	transformed_ray = ray;
	ftm_m4_inversion(&inv, curr->matrix);
	transform_ray(&transformed_ray, ray, inv);
	return (intersect_shape(curr, transformed_ray));
}

bool	check_shadow_intersection(t_obj_node *node, double dist, double *min_t)
{
	if (node->t && node->t[0] >= 0
			&& node->t[0] < dist && node->t[0] < *min_t)
	{
		*min_t = node->t[0];
		return (true);
	}
	return (false);
}

bool	check_objects_for_shadow(t_scene *scene, t_ray ray, double distance)
{
	t_obj_node	*curr;
	double		min_t;
	bool		shadowed;

	shadowed = false;
	min_t = INFINITY;
	curr = scene->obj_list->head;
	while (curr)
	{
		if (!get_transformed_intersection(curr, ray))
			return (false);
		if (check_shadow_intersection(curr, distance, &min_t))
			shadowed = true;
		curr = curr->next;
	}
	return (shadowed);
}

bool	is_shadowed(t_scene *scene, t_tuples point, t_light curr)
{
	t_ray	ray;
	double	distance;
	bool	shadowed;

	get_shadow_ray(&ray, point, &distance, curr);
	shadowed = check_objects_for_shadow(scene, ray, distance);
	return (shadowed);
}
