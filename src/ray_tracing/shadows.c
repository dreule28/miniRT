#include "mini_rt.h"

t_rgb	*shade_hit(t_scene *scene, t_computations *comps, t_light *curr)
{
	comps->in_shadow = is_shadowed(scene, comps->over_point);
	return (lighting(scene, comps, curr));
}

bool	is_shadowed(t_scene *scene, t_tuples *point)
{
	t_tuples	*distance_v;
	double		distance;
	t_tuples	*direction;
	t_ray		*ray;
	double		*hit;

	distance_v = ftm_tup_subtract(&scene->light_list->head->pos, point);
	distance = magnitude_vector(distance_v);
	direction = ftm_tup_norm(distance_v);
	ray = init_ray(copy_point(point), direction);
	intersect_to_list(scene, ray);
	hit = hit_obj(scene);
	free_tuple(distance_v);
	free_tuple(direction);
	free(ray);
	return (hit && hit[0] < distance);
}
