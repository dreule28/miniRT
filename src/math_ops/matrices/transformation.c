/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:58:36 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 14:58:37 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_m4	ftm_translation(t_tuples tuple)
{
	t_m4		matrix;
	t_m4_col	col_values;

	init_identity(&matrix);
	col_values = (t_m4_col){tuple.x, tuple.y, tuple.z, 1};
	assign_m4_col(&matrix.col3, col_values);
	return (matrix);
}

t_m4	ftm_scaling(t_tuples tuple)
{
	t_m4	identity_matrix;

	init_identity(&identity_matrix);
	identity_matrix.col0.x = identity_matrix.col0.x * tuple.x;
	identity_matrix.col1.y = identity_matrix.col1.y * tuple.y;
	identity_matrix.col2.z = identity_matrix.col2.z * tuple.z;
	return (identity_matrix);
}
