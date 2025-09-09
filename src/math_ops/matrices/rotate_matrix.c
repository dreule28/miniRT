/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:58:35 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 14:58:36 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_m4	ftm_rotate_x(double radians)
{
	t_m4		matrix;
	t_m4_col	col_values;

	col_values = (t_m4_col){1, 0, 0, 0};
	assign_m4_col(&matrix.col0, col_values);
	col_values = (t_m4_col){0, cos(radians), sin(radians), 0};
	assign_m4_col(&matrix.col1, col_values);
	col_values = (t_m4_col){0, -sin(radians), cos(radians), 0};
	assign_m4_col(&matrix.col2, col_values);
	col_values = (t_m4_col){0, 0, 0, 1};
	assign_m4_col(&matrix.col3, col_values);
	return (matrix);
}

t_m4	ftm_rotate_y(double radians)
{
	t_m4		matrix;
	t_m4_col	col_values;

	col_values = (t_m4_col){cos(radians), 0, -sin(radians), 0};
	assign_m4_col(&matrix.col0, col_values);
	col_values = (t_m4_col){0, 1, 0, 0};
	assign_m4_col(&matrix.col1, col_values);
	col_values = (t_m4_col){sin(radians), 0, cos(radians), 0};
	assign_m4_col(&matrix.col2, col_values);
	col_values = (t_m4_col){0, 0, 0, 1};
	assign_m4_col(&matrix.col3, col_values);
	return (matrix);
}

t_m4	ftm_rotate_z(double radians)
{
	t_m4		matrix;
	t_m4_col	col_values;

	col_values = (t_m4_col){cos(radians), sin(radians), 0, 0};
	assign_m4_col(&matrix.col0, col_values);
	col_values = (t_m4_col){-sin(radians), cos(radians), 0, 0};
	assign_m4_col(&matrix.col1, col_values);
	col_values = (t_m4_col){0, 0, 1, 0};
	assign_m4_col(&matrix.col2, col_values);
	col_values = (t_m4_col){0, 0, 0, 1};
	assign_m4_col(&matrix.col3, col_values);
	return (matrix);
}

double	radians(double degree)
{
	return (degree * M_PI / 180.0);
}
