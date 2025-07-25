#include "mini_rt.h"

void	free_ray(t_ray *ray)
{
	if (ray)
	{
		if (ray->direction)
			free_tuple(ray->direction);
		if (ray->origin)
			free_tuple(ray->origin);
		free(ray);
	}
}

t_ray	*init_ray(t_tuples *origin, t_tuples *direction)
{
	t_ray	*ray;

	ray = ft_calloc(sizeof(t_ray), 1);
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
	pos = ftm_tup_add(ray->origin, scalar);
	free(scalar);
	return (pos);
}

t_ray	*transform_ray(t_ray *ray, t_m4 *m4)
{
	t_ray	*new_ray;

	if (!ray || !ray->direction || !ray->origin || !m4)
		return (NULL);
	new_ray = ft_calloc(sizeof(t_ray), 1);
	if (!new_ray)
		return (NULL);
	new_ray->direction = ftm_matrix_times_tuple(m4, ray->direction);
	new_ray->origin = ftm_matrix_times_tuple(m4, ray->origin);
	return (new_ray);
}

void	set_transform(t_obj_node *curr, t_m4 *translation_matrix)
{
	if (curr->matrix)
	{
		free(curr->matrix->col0);
		free(curr->matrix->col1);
		free(curr->matrix->col2);
		free(curr->matrix->col3);
		free(curr->matrix);
	}
	curr->matrix = translation_matrix;
}
