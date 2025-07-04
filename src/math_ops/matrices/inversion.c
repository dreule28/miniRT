#include "mini_rt.h"

bool	is_inversible(double determinante)
{
	if (determinante == 0.0)
		return (false);
	else
		return (true);
}

void	apply_col_inversion(t_m4 *m4, t_m4 *new_m4, double dmt)
{
	if (new_m4->col0 == NULL)
	{
		new_m4->col0 = assign_m4_col(ftm_m4_cofactor(m4, 0, 0) / dmt,
				ftm_m4_cofactor(m4, 0, 1) / dmt, ftm_m4_cofactor(m4, 0, 2)
				/ dmt, ftm_m4_cofactor(m4, 0, 3) / dmt);
	}
	if (new_m4->col1 == NULL)
	{
		new_m4->col1 = assign_m4_col(ftm_m4_cofactor(m4, 1, 0) / dmt,
				ftm_m4_cofactor(m4, 1, 1) / dmt, ftm_m4_cofactor(m4, 1, 2)
				/ dmt, ftm_m4_cofactor(m4, 1, 3) / dmt);
	}
	if (new_m4->col2 == NULL)
	{
		new_m4->col2 = assign_m4_col(ftm_m4_cofactor(m4, 2, 0) / dmt,
				ftm_m4_cofactor(m4, 2, 1) / dmt, ftm_m4_cofactor(m4, 2, 2)
				/ dmt, ftm_m4_cofactor(m4, 2, 3) / dmt);
	}
	if (new_m4->col3 == NULL)
	{
		new_m4->col3 = assign_m4_col(ftm_m4_cofactor(m4, 3, 0) / dmt,
				ftm_m4_cofactor(m4, 3, 1) / dmt, ftm_m4_cofactor(m4, 3, 2)
				/ dmt, ftm_m4_cofactor(m4, 3, 3) / dmt);
	}
}

t_m4	*ftm_m4_inversion(t_m4 *m4)
{
	t_m4	*new_m4;
	double	dmt;
	int		count;

	count = 0;
	new_m4 = init_m4();
	dmt = ftm_m4_dmt(m4);
	while (count < 4)
	{
		apply_col_inversion(m4, new_m4, dmt);
		count++;
	}
	return (new_m4);
}
