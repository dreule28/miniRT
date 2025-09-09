/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inversion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:58:26 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 14:58:27 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

bool	is_inversible(double determinante)
{
	if (determinante == 0.0)
		return (false);
	else
		return (true);
}

void	apply_col_inversion(t_m4 m4, t_m4 *new_m4, double dmt)
{
	t_m4_col	col_values;

	col_values = (t_m4_col){ftm_m4_cofactor(m4, 0, 0) / dmt,
		ftm_m4_cofactor(m4, 1, 0) / dmt,
		ftm_m4_cofactor(m4, 2, 0) / dmt,
		ftm_m4_cofactor(m4, 3, 0) / dmt};
	assign_m4_col(&new_m4->col0, col_values);
	col_values = (t_m4_col){ftm_m4_cofactor(m4, 0, 1) / dmt,
		ftm_m4_cofactor(m4, 1, 1) / dmt,
		ftm_m4_cofactor(m4, 2, 1) / dmt,
		ftm_m4_cofactor(m4, 3, 1) / dmt};
	assign_m4_col(&new_m4->col1, col_values);
	col_values = (t_m4_col){ftm_m4_cofactor(m4, 0, 2) / dmt,
		ftm_m4_cofactor(m4, 1, 2) / dmt,
		ftm_m4_cofactor(m4, 2, 2) / dmt,
		ftm_m4_cofactor(m4, 3, 2) / dmt};
	assign_m4_col(&new_m4->col2, col_values);
	col_values = (t_m4_col){ftm_m4_cofactor(m4, 0, 3) / dmt,
		ftm_m4_cofactor(m4, 1, 3) / dmt,
		ftm_m4_cofactor(m4, 2, 3) / dmt,
		ftm_m4_cofactor(m4, 3, 3) / dmt};
	assign_m4_col(&new_m4->col3, col_values);
}

void	ftm_m4_inversion(t_m4 *new_m4, t_m4 m4)
{
	double	dmt;
	int		count;

	count = 0;
	dmt = ftm_m4_dmt(m4);
	while (count < 4)
	{
		apply_col_inversion(m4, new_m4, dmt);
		count++;
	}
}
