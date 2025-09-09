#include "mini_rt.h"

double	ftm_m_minor(t_m3 m3, int col, int row)
{
	t_m2	m2;
	double	result;

	ftm_m3_subm(&m2, m3, col, row);
	result = ftm_m_dmt(m2);
	return (result);
}

double	ftm_m3_cofactor(t_m3 m3, int col, int row)
{
	t_m2	m2;
	double	result;

	ftm_m3_subm(&m2, m3, col, row);
	result = ftm_m_dmt(m2);
	if ((row + col) % 2 != 0)
		result = -result;
	return (result);
}

double	ftm_m4_cofactor(t_m4 m4, int col, int row)
{
	t_m3	m3;
	double	result;

	ftm_m4_subm(&m3, m4, col, row);
	result = ftm_m3_dmt(m3);
	if ((row + col) % 2 != 0)
		result = -result;
	return (result);
}
