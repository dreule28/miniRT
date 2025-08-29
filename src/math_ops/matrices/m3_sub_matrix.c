#include "mini_rt.h"

void	ftm_m3_subm(t_m2 *m2, t_m3 m3, int col, int row)
{
	if (col > 2 || row > 2 || col < 0 || row < 0)
	{
		ft_putstr_fd("Error\nWrong number of rows\n", 2);
		return ;
	}
	if (col == 0)
		m3_subm_col_0(m3, m2, row);
	if (col == 1)
		m3_subm_col_1(m3, m2, row);
	if (col == 2)
		m3_subm_col_2(m3, m2, row);
}

void	m3_subm_col_0(t_m3 m3, t_m2 *m2, int row)
{
	if (row == 0)
	{
		assign_m2_col(&m2->col0, m3.col1.y, m3.col1.z);
		assign_m2_col(&m2->col1, m3.col2.y, m3.col2.z);
	}
	if (row == 1)
	{
		assign_m2_col(&m2->col0, m3.col1.x, m3.col1.z);
		assign_m2_col(&m2->col1, m3.col2.x, m3.col2.z);
	}
	if (row == 2)
	{
		assign_m2_col(&m2->col0, m3.col1.x, m3.col1.y);
		assign_m2_col(&m2->col1, m3.col2.x, m3.col2.y);
	}
}

void	m3_subm_col_1(t_m3 m3, t_m2 *m2, int row)
{
	if (row == 0)
	{
		assign_m2_col(&m2->col0, m3.col0.y, m3.col0.z);
		assign_m2_col(&m2->col1, m3.col2.y, m3.col2.z);
	}
	if (row == 1)
	{
		assign_m2_col(&m2->col0, m3.col0.x, m3.col0.z);
		assign_m2_col(&m2->col1, m3.col2.x, m3.col2.z);
	}
	if (row == 2)
	{
		assign_m2_col(&m2->col0, m3.col0.x, m3.col0.y);
		assign_m2_col(&m2->col1, m3.col2.x, m3.col2.y);
	}
}

void	m3_subm_col_2(t_m3 m3, t_m2 *m2, int row)
{
	if (row == 0)
	{
		assign_m2_col(&m2->col0, m3.col0.y, m3.col0.z);
		assign_m2_col(&m2->col1, m3.col1.y, m3.col1.z);
	}
	if (row == 1)
	{
		assign_m2_col(&m2->col0, m3.col0.x, m3.col0.z);
		assign_m2_col(&m2->col1, m3.col1.x, m3.col1.z);
	}
	if (row == 2)
	{
		assign_m2_col(&m2->col0, m3.col0.x, m3.col0.y);
		assign_m2_col(&m2->col1, m3.col1.x, m3.col1.y);
	}
}
