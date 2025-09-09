/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:58:37 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 14:58:38 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ftm_transpose_matrix(t_m4 *new_matrix, t_m4 old_matrix)
{
	t_m4_col	col_values;

	col_values = (t_m4_col){old_matrix.col0.x, old_matrix.col1.x,
		old_matrix.col2.x, old_matrix.col3.x};
	assign_m4_col(&new_matrix->col0, col_values);
	col_values = (t_m4_col){old_matrix.col0.y, old_matrix.col1.y,
		old_matrix.col2.y, old_matrix.col3.y};
	assign_m4_col(&new_matrix->col1, col_values);
	col_values = (t_m4_col){old_matrix.col0.z, old_matrix.col1.z,
		old_matrix.col2.z, old_matrix.col3.z};
	assign_m4_col(&new_matrix->col2, col_values);
	col_values = (t_m4_col){old_matrix.col0.w, old_matrix.col1.w,
		old_matrix.col2.w, old_matrix.col3.w};
	assign_m4_col(&new_matrix->col3, col_values);
}
