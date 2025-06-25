#include "mini_rt.h"

/*calculates the determenant of an 2x2 matrix*/
double m_dmt(t_m2 *m2)
{
	double x;
	double y;
	double result;
	x = m2->col0->x * m2->col1->y;
	y = m2->col0->y * m2->col1->x;
	result = x - y;
	return(result);
}

double	m_minor(t_m3 *m3, int col, int row)
{
	t_m2 *m2;
	double result;

	m2 = m3_subm(m3, col, row);
	result = m_dmt(m2);
	return(result);
}

