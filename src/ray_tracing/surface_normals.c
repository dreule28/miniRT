/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_normals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:00:02 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 15:00:10 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	normal_at(t_tuples *normal, t_obj_node curr, t_tuples world_point)
{
	t_m4		inverse;
	t_tuples	object_point;
	t_tuples	object_normal_vec;
	t_tuples	world_normal;
	t_m4		transpose;

	ftm_m4_inversion(&inverse, curr.matrix);
	ftm_matrix_times_tuple(&object_point, inverse, world_point);
	local_normal_at(&object_normal_vec, curr, object_point);
	ftm_transpose_matrix(&transpose, inverse);
	ftm_matrix_times_tuple(&world_normal, transpose, object_normal_vec);
	ftm_tup_norm(normal, world_normal);
}
