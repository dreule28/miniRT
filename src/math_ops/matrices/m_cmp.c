#include "mini_rt.h"

bool	ftm_m_cmp(void *matrix1, void *matrix2, int size)
{
	if (size == 2)
		return (ftm_m2_cmp((t_m2 *)matrix1, (t_m2 *)matrix2));
	else if (size == 3)
		return (ftm_m3_cmp((t_m3 *)matrix1, (t_m3 *)matrix2));
	else if (size == 4)
		return (ftm_m4_cmp((t_m4 *)matrix1, (t_m4 *)matrix2));
	return (false);
}

bool	ftm_m2_cmp(t_m2 *matrix1, t_m2 *matrix2)
{
	if (!matrix1 && !matrix2)
		return (true);
	if (!matrix1 || !matrix2)
		return (false);
	return (cmp_m2_col(&matrix1->col0, &matrix2->col0)
		&& cmp_m2_col(&matrix1->col1, &matrix2->col1));
}

bool	ftm_m3_cmp(t_m3 *matrix1, t_m3 *matrix2)
{
	if (!matrix1 && !matrix2)
		return (true);
	if (!matrix1 || !matrix2)
		return (false);
	return (cmp_m3_col(&matrix1->col0, &matrix2->col0)
		&& cmp_m3_col(&matrix1->col1, &matrix2->col1)
		&& cmp_m3_col(&matrix1->col2, &matrix2->col2));
}

bool	ftm_m4_cmp(t_m4 *matrix1, t_m4 *matrix2)
{
	if (!matrix1 && !matrix2)
		return (true);
	if (!matrix1 || !matrix2)
		return (false);
	return (cmp_m4_col(&matrix1->col0, &matrix2->col0)
		&& cmp_m4_col(&matrix1->col1, &matrix2->col1)
		&& cmp_m4_col(&matrix1->col2, &matrix2->col2)
		&& cmp_m4_col(&matrix1->col3, &matrix2->col3));
}
