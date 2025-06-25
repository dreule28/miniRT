#include "mini_rt.h"

/*calculates the determenant of an 2x2 matrix*/
double	m_dmt(t_m2 *m2)
{
	double	x;
	double	y;
	double	result;

	x = m2->col0->x * m2->col1->y;
	y = m2->col0->y * m2->col1->x;
	result = x - y;
	return (result);
}

double	m_minor(t_m3 *m3, int col, int row)
{
	t_m2	*m2;
	double	result;

	m2 = m3_subm(m3, col, row);
	result = m_dmt(m2);
	return (result);
}

double	m_cofactor(t_m3 *m3, int col, int row)
{
	t_m2	*m2;
	double	result;

	m2 = m3_subm(m3, col, row);
	result = m_dmt(m2);
	if ((row + col) % 2 != 0)
		result = -result;
	return (result);
}

t_m3	*ftm_cofomatrix(t_m3 *m3)
{
	t_m3	*cofomatrix;

	cofomatrix = init_m3();
	if (!cofomatrix)
		return (NULL);
	cofomatrix->col0 = assign_m3_col(m_cofactor(m3, 0, 0), m_cofactor(m3, 0, 1),
			m_cofactor(m3, 0, 2));
	cofomatrix->col1 = assign_m3_col(m_cofactor(m3, 1, 0), m_cofactor(m3, 1, 1),
			m_cofactor(m3, 1, 2));
	cofomatrix->col2 = assign_m3_col(m_cofactor(m3, 2, 0), m_cofactor(m3, 2, 1),
			m_cofactor(m3, 2, 2));
	return (cofomatrix);
}
