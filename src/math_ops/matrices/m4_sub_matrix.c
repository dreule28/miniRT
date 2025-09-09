/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_sub_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:58:30 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 14:58:31 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ftm_m4_subm(t_m3 *m3, t_m4 m4, int col, int row)
{
	if (col > 3 || row > 3 || col < 0 || row < 0)
	{
		ft_putstr_fd("Error\nwrong number of rows in m4_subm\n", 2);
		return ;
	}
	if (col == 0)
		m4_subm_col_0(m4, m3, row);
	if (col == 1)
		m4_subm_col_1(m4, m3, row);
	if (col == 2)
		m4_subm_col_2(m4, m3, row);
	if (col == 3)
		m4_subm_col_3(m4, m3, row);
}

void	m4_subm_col_0(t_m4 m4, t_m3 *m3, int row)
{
	if (row == 0)
	{
		assign_m3_col(&m3->col0, m4.col1.y, m4.col1.z, m4.col1.w);
		assign_m3_col(&m3->col1, m4.col2.y, m4.col2.z, m4.col2.w);
		assign_m3_col(&m3->col2, m4.col3.y, m4.col3.z, m4.col3.w);
	}
	if (row == 1)
	{
		assign_m3_col(&m3->col0, m4.col1.x, m4.col1.z, m4.col1.w);
		assign_m3_col(&m3->col1, m4.col2.x, m4.col2.z, m4.col2.w);
		assign_m3_col(&m3->col2, m4.col3.x, m4.col3.z, m4.col3.w);
	}
	if (row == 2)
	{
		assign_m3_col(&m3->col0, m4.col1.x, m4.col1.y, m4.col1.w);
		assign_m3_col(&m3->col1, m4.col2.x, m4.col2.y, m4.col2.w);
		assign_m3_col(&m3->col2, m4.col3.x, m4.col3.y, m4.col3.w);
	}
	if (row == 3)
	{
		assign_m3_col(&m3->col0, m4.col1.x, m4.col1.y, m4.col1.z);
		assign_m3_col(&m3->col1, m4.col2.x, m4.col2.y, m4.col2.z);
		assign_m3_col(&m3->col2, m4.col3.x, m4.col3.y, m4.col3.z);
	}
}

void	m4_subm_col_1(t_m4 m4, t_m3 *m3, int row)
{
	if (row == 0)
	{
		assign_m3_col(&m3->col0, m4.col0.y, m4.col0.z, m4.col0.w);
		assign_m3_col(&m3->col1, m4.col2.y, m4.col2.z, m4.col2.w);
		assign_m3_col(&m3->col2, m4.col3.y, m4.col3.z, m4.col3.w);
	}
	if (row == 1)
	{
		assign_m3_col(&m3->col0, m4.col0.x, m4.col0.z, m4.col0.w);
		assign_m3_col(&m3->col1, m4.col2.x, m4.col2.z, m4.col2.w);
		assign_m3_col(&m3->col2, m4.col3.x, m4.col3.z, m4.col3.w);
	}
	if (row == 2)
	{
		assign_m3_col(&m3->col0, m4.col0.x, m4.col0.y, m4.col0.w);
		assign_m3_col(&m3->col1, m4.col2.x, m4.col2.y, m4.col2.w);
		assign_m3_col(&m3->col2, m4.col3.x, m4.col3.y, m4.col3.w);
	}
	if (row == 3)
	{
		assign_m3_col(&m3->col0, m4.col0.x, m4.col0.y, m4.col0.z);
		assign_m3_col(&m3->col1, m4.col2.x, m4.col2.y, m4.col2.z);
		assign_m3_col(&m3->col2, m4.col3.x, m4.col3.y, m4.col3.z);
	}
}

void	m4_subm_col_2(t_m4 m4, t_m3 *m3, int row)
{
	if (row == 0)
	{
		assign_m3_col(&m3->col0, m4.col0.y, m4.col0.z, m4.col0.w);
		assign_m3_col(&m3->col1, m4.col1.y, m4.col1.z, m4.col1.w);
		assign_m3_col(&m3->col2, m4.col3.y, m4.col3.z, m4.col3.w);
	}
	if (row == 1)
	{
		assign_m3_col(&m3->col0, m4.col0.x, m4.col0.z, m4.col0.w);
		assign_m3_col(&m3->col1, m4.col1.x, m4.col1.z, m4.col1.w);
		assign_m3_col(&m3->col2, m4.col3.x, m4.col3.z, m4.col3.w);
	}
	if (row == 2)
	{
		assign_m3_col(&m3->col0, m4.col0.x, m4.col0.y, m4.col0.w);
		assign_m3_col(&m3->col1, m4.col1.x, m4.col1.y, m4.col1.w);
		assign_m3_col(&m3->col2, m4.col3.x, m4.col3.y, m4.col3.w);
	}
	if (row == 3)
	{
		assign_m3_col(&m3->col0, m4.col0.x, m4.col0.y, m4.col0.z);
		assign_m3_col(&m3->col1, m4.col1.x, m4.col1.y, m4.col1.z);
		assign_m3_col(&m3->col2, m4.col3.x, m4.col3.y, m4.col3.z);
	}
}

void	m4_subm_col_3(t_m4 m4, t_m3 *m3, int row)
{
	if (row == 0)
	{
		assign_m3_col(&m3->col0, m4.col0.y, m4.col0.z, m4.col0.w);
		assign_m3_col(&m3->col1, m4.col1.y, m4.col1.z, m4.col1.w);
		assign_m3_col(&m3->col2, m4.col2.y, m4.col2.z, m4.col2.w);
	}
	if (row == 1)
	{
		assign_m3_col(&m3->col0, m4.col0.x, m4.col0.z, m4.col0.w);
		assign_m3_col(&m3->col1, m4.col1.x, m4.col1.z, m4.col1.w);
		assign_m3_col(&m3->col2, m4.col2.x, m4.col2.z, m4.col2.w);
	}
	if (row == 2)
	{
		assign_m3_col(&m3->col0, m4.col0.x, m4.col0.y, m4.col0.w);
		assign_m3_col(&m3->col1, m4.col1.x, m4.col1.y, m4.col1.w);
		assign_m3_col(&m3->col2, m4.col2.x, m4.col2.y, m4.col2.w);
	}
	if (row == 3)
	{
		assign_m3_col(&m3->col0, m4.col0.x, m4.col0.y, m4.col0.z);
		assign_m3_col(&m3->col1, m4.col1.x, m4.col1.y, m4.col1.z);
		assign_m3_col(&m3->col2, m4.col2.x, m4.col2.y, m4.col2.z);
	}
}
