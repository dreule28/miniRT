#include "mini_rt.h"

/* m4_subm: Creates a 3x3 matrix from a 4x4 matrix by removing one row and 
 * one column
 * @param m4:  Source 4x4 matrix
 * @param col: Column to remove (0-3)
 * @param row: Row to remove (0-3)
 * @return:    New 3x3 matrix with specified row and column removed
 */
t_m3	*ftm_m4_subm(t_m4 *m4, int col, int row)
{
	t_m3	*m3;

	if (!m4)
		return (NULL);
	if (col > 3 || row > 3 || col < 0 || row < 0)
	{
		ft_putstr_fd("Error\nwrong number of rows in m4_subm\n", 2);
		return (NULL);
	}
	m3 = init_m3();
	if (col == 0)
		m4_subm_col_0(m4, m3, &row);
	if (col == 1)
		m4_subm_col_1(m4, m3, &row);
	if (col == 2)
		m4_subm_col_2(m4, m3, &row);
	if (col == 3)
		m4_subm_col_3(m4, m3, &row);
	return (m3);
}

void	m4_subm_col_0(t_m4 *m4, t_m3 *m3, int *row)
{
	if (*row == 0)
	{
		m3->col0 = assign_m3_col(m4->col1->y, m4->col1->z, m4->col1->w);
		m3->col1 = assign_m3_col(m4->col2->y, m4->col2->z, m4->col2->w);
		m3->col2 = assign_m3_col(m4->col3->y, m4->col3->z, m4->col3->w);
	}
	if (*row == 1)
	{
		m3->col0 = assign_m3_col(m4->col1->x, m4->col1->z, m4->col1->w);
		m3->col1 = assign_m3_col(m4->col2->x, m4->col2->z, m4->col2->w);
		m3->col2 = assign_m3_col(m4->col3->x, m4->col3->z, m4->col3->w);
	}
	if (*row == 2)
	{
		m3->col0 = assign_m3_col(m4->col1->x, m4->col1->y, m4->col1->w);
		m3->col1 = assign_m3_col(m4->col2->x, m4->col2->y, m4->col2->w);
		m3->col2 = assign_m3_col(m4->col3->x, m4->col3->y, m4->col3->w);
	}
	if (*row == 3)
	{
		m3->col0 = assign_m3_col(m4->col1->x, m4->col1->y, m4->col1->z);
		m3->col1 = assign_m3_col(m4->col2->x, m4->col2->y, m4->col2->z);
		m3->col2 = assign_m3_col(m4->col3->x, m4->col3->y, m4->col3->z);
	}
}

void	m4_subm_col_1(t_m4 *m4, t_m3 *m3, int *row)
{
	if (*row == 0)
	{
		m3->col0 = assign_m3_col(m4->col0->y, m4->col0->z, m4->col0->w);
		m3->col1 = assign_m3_col(m4->col2->y, m4->col2->z, m4->col2->w);
		m3->col2 = assign_m3_col(m4->col3->y, m4->col3->z, m4->col3->w);
	}
	if (*row == 1)
	{
		m3->col0 = assign_m3_col(m4->col0->x, m4->col0->z, m4->col0->w);
		m3->col1 = assign_m3_col(m4->col2->x, m4->col2->z, m4->col2->w);
		m3->col2 = assign_m3_col(m4->col3->x, m4->col3->z, m4->col3->w);
	}
	if (*row == 2)
	{
		m3->col0 = assign_m3_col(m4->col0->x, m4->col0->y, m4->col0->w);
		m3->col1 = assign_m3_col(m4->col2->x, m4->col2->y, m4->col2->w);
		m3->col2 = assign_m3_col(m4->col3->x, m4->col3->y, m4->col3->w);
	}
	if (*row == 3)
	{
		m3->col0 = assign_m3_col(m4->col0->x, m4->col0->y, m4->col0->z);
		m3->col1 = assign_m3_col(m4->col2->x, m4->col2->y, m4->col2->z);
		m3->col2 = assign_m3_col(m4->col3->x, m4->col3->y, m4->col3->z);
	}
}

void	m4_subm_col_2(t_m4 *m4, t_m3 *m3, int *row)
{
	if (*row == 0)
	{
		m3->col0 = assign_m3_col(m4->col0->y, m4->col0->z, m4->col0->w);
		m3->col1 = assign_m3_col(m4->col1->y, m4->col1->z, m4->col1->w);
		m3->col2 = assign_m3_col(m4->col3->y, m4->col3->z, m4->col3->w);
	}
	if (*row == 1)
	{
		m3->col0 = assign_m3_col(m4->col0->x, m4->col0->z, m4->col0->w);
		m3->col1 = assign_m3_col(m4->col1->x, m4->col1->z, m4->col1->w);
		m3->col2 = assign_m3_col(m4->col3->x, m4->col3->z, m4->col3->w);
	}
	if (*row == 2)
	{
		m3->col0 = assign_m3_col(m4->col0->x, m4->col0->y, m4->col0->w);
		m3->col1 = assign_m3_col(m4->col1->x, m4->col1->y, m4->col1->w);
		m3->col2 = assign_m3_col(m4->col3->x, m4->col3->y, m4->col3->w);
	}
	if (*row == 3)
	{
		m3->col0 = assign_m3_col(m4->col0->x, m4->col0->y, m4->col0->z);
		m3->col1 = assign_m3_col(m4->col1->x, m4->col1->y, m4->col1->z);
		m3->col2 = assign_m3_col(m4->col3->x, m4->col3->y, m4->col3->z);
	}
}

void	m4_subm_col_3(t_m4 *m4, t_m3 *m3, int *row)
{
	if (*row == 0)
	{
		m3->col0 = assign_m3_col(m4->col0->y, m4->col0->z, m4->col0->w);
		m3->col1 = assign_m3_col(m4->col1->y, m4->col1->z, m4->col1->w);
		m3->col2 = assign_m3_col(m4->col2->y, m4->col2->z, m4->col2->w);
	}
	if (*row == 1)
	{
		m3->col0 = assign_m3_col(m4->col0->x, m4->col0->z, m4->col0->w);
		m3->col1 = assign_m3_col(m4->col1->x, m4->col1->z, m4->col1->w);
		m3->col2 = assign_m3_col(m4->col2->x, m4->col2->z, m4->col2->w);
	}
	if (*row == 2)
	{
		m3->col0 = assign_m3_col(m4->col0->x, m4->col0->y, m4->col0->w);
		m3->col1 = assign_m3_col(m4->col1->x, m4->col1->y, m4->col1->w);
		m3->col2 = assign_m3_col(m4->col2->x, m4->col2->y, m4->col2->w);
	}
	if (*row == 3)
	{
		m3->col0 = assign_m3_col(m4->col0->x, m4->col0->y, m4->col0->z);
		m3->col1 = assign_m3_col(m4->col1->x, m4->col1->y, m4->col1->z);
		m3->col2 = assign_m3_col(m4->col2->x, m4->col2->y, m4->col2->z);
	}
}
