#include "mini_rt.h"

t_m3	*m4_subm(t_m4 *m4, int col, int row)
{
	t_m3	*m3;

	if (!m4)
		return (NULL);
	if (col > 3 || row > 3 || col < 0 || row < 0)
	{
		ft_putstr_fd("wrong number of rows in m4_subm\n", 2);
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
}
