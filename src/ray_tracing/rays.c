/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:59:56 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 14:59:57 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	init_ray(t_ray *ray, t_tuples origin, t_tuples direction)
{
	ray->origin = origin;
	ray->direction = direction;
}

void	ray_position(t_tuples *point, t_ray *ray, double time)
{
	t_tuples	scalar;

	init_point(point, 0, 0, 0);
	ftm_tup_mult(&scalar, ray->direction, time);
	ftm_tup_add(point, ray->origin, scalar);
}

void	transform_ray(t_ray *new_ray, t_ray old_ray, t_m4 m4)
{
	ftm_matrix_times_tuple(&new_ray->direction, m4, old_ray.direction);
	ftm_matrix_times_tuple(&new_ray->origin, m4, old_ray.origin);
}

void	set_transform(t_obj_node *curr, t_m4 *translation_matrix)
{
	if (&curr->matrix)
	{
		free(&curr->matrix.col0);
		free(&curr->matrix.col1);
		free(&curr->matrix.col2);
		free(&curr->matrix.col3);
		free(&curr->matrix);
	}
	curr->matrix = *translation_matrix;
}
