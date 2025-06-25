#include "mini_rt.h"

t_m2	*m3_subm(t_m3 *m3, int col, int row)
{
	t_m2	*m2;

	if (!m3)
		return (NULL);
	if (col > 2 || row > 2 || col < 0 || row < 0)
	{
		ft_putstr_fd("wrong number of rows\n", 2);
		return (NULL);
	}
	m2 = init_m2();
	if (col == 0)
		m3_subm_col_0(m3, m2, &row);
	if (col == 1)
		m3_subm_col_1(m3, m2, &row);
	if (col == 2)
		m3_subm_col_2(m3, m2, &row);
	return (m2);
}

void	m3_subm_col_0(t_m3 *m3, t_m2 *m2, int *row)
{
	if (*row == 0)
	{
		m2->col0 = assign_m2_col(m3->col1->y, m3->col1->z);
		m2->col1 = assign_m2_col(m3->col2->y, m3->col2->z);
	}
	if (*row == 1)
	{
		m2->col0 = assign_m2_col(m3->col1->x, m3->col1->z);
		m2->col1 = assign_m2_col(m3->col2->x, m3->col2->z);
	}
	if (*row == 2)
	{
		m2->col0 = assign_m2_col(m3->col1->x, m3->col1->y);
		m2->col1 = assign_m2_col(m3->col2->x, m3->col2->y);
	}
}

void	m3_subm_col_1(t_m3 *m3, t_m2 *m2, int *row)
{
	if (*row == 0)
	{
		m2->col0 = assign_m2_col(m3->col0->y, m3->col0->z);
		m2->col1 = assign_m2_col(m3->col2->y, m3->col2->z);
	}
	if (*row == 1)
	{
		m2->col0 = assign_m2_col(m3->col0->x, m3->col0->z);
		m2->col1 = assign_m2_col(m3->col2->x, m3->col2->z);
	}
	if (*row == 2)
	{
		m2->col0 = assign_m2_col(m3->col0->x, m3->col0->y);
		m2->col1 = assign_m2_col(m3->col2->x, m3->col2->y);
	}
}

void	m3_subm_col_2(t_m3 *m3, t_m2 *m2, int *row)
{
	if (*row == 0)
	{
		m2->col0 = assign_m2_col(m3->col0->y, m3->col0->z);
		m2->col1 = assign_m2_col(m3->col1->y, m3->col1->z);
	}
	if (*row == 1)
	{
		m2->col0 = assign_m2_col(m3->col0->x, m3->col0->z);
		m2->col1 = assign_m2_col(m3->col1->x, m3->col1->z);
	}
	if (*row == 2)
	{
		m2->col0 = assign_m2_col(m3->col0->x, m3->col0->y);
		m2->col1 = assign_m2_col(m3->col1->x, m3->col1->y);
	}
}
