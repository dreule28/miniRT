#include "mini_rt.h"

double	ftm_m_minor(t_m3 *m3, int col, int row)
{
	t_m2	*m2;
	double	result;

	m2 = ftm_m3_subm(m3, col, row);
	result = ftm_m_dmt(m2);
	return (result);
}

double	ftm_m3_cofactor(t_m3 *m3, int col, int row)
{
	t_m2	*m2;
	double	result;

	m2 = ftm_m3_subm(m3, col, row);
	result = ftm_m_dmt(m2);
	if ((row + col) % 2 != 0)
		result = -result;
	return (result);
}

double	ftm_m4_cofactor(t_m4 *m4, int col, int row)
{
	t_m3	*m3;
	double	result;

	m3 = ftm_m4_subm(m4, col, row);
	result = ftm_m3_dmt(m3);
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
	cofomatrix->col0 = assign_m3_col(ftm_m3_cofactor(m3, 0, 0),
			ftm_m3_cofactor(m3, 0, 1), ftm_m3_cofactor(m3, 0, 2));
	cofomatrix->col1 = assign_m3_col(ftm_m3_cofactor(m3, 1, 0),
			ftm_m3_cofactor(m3, 1, 1), ftm_m3_cofactor(m3, 1, 2));
	cofomatrix->col2 = assign_m3_col(ftm_m3_cofactor(m3, 2, 0),
			ftm_m3_cofactor(m3, 2, 1), ftm_m3_cofactor(m3, 2, 2));
	return (cofomatrix);
}
