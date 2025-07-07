#include "mini_rt.h"

void	free_ray(t_ray *ray)
{
	if (!ray)
		free(ray);
}

t_ray	*init_ray(t_tuples *origin, t_tuples *direction)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->origin = origin;
	ray->direction = direction;
	return (ray);
}

t_tuples	*ray_position(t_ray *ray, double time)
{
	t_tuples	*pos;
	t_tuples	*scalar;

	pos = init_point(0, 0, 0);
	if (!pos)
		return (NULL);
	scalar = ftm_tup_mult(ray->direction, time);
	if (!scalar)
		return (NULL);
	pos = ftm_tup_add(pos, scalar);
	free(scalar);
	return (pos);
}
