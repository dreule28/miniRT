#include "mini_rt.h"

bool	cmp_m2_col(t_m2_col *col0, t_m2_col *col1)
{
	if (!col0 && !col1)
		return (true);
	if (!col0 || !col1)
		return (false);
	return (fabs(col0->x - col1->x) <= DBL_EPSILON
			&& fabs(col0->y - col1->y) <= DBL_EPSILON);
}

bool	cmp_m3_col(t_m3_col *col0, t_m3_col *col1)
{
	if (!col0 && !col1)
		return (true);
	if (!col0 || !col1)
		return (false);
	return (fabs(col0->x - col1->x) <= DBL_EPSILON
			&& fabs(col0->y - col1->y) <= DBL_EPSILON
			&& fabs(col0->z - col1->z) <= DBL_EPSILON);
}

bool	cmp_m4_col(t_m4_col *col0, t_m4_col *col1)
{
	if (!col0 && !col1)
		return (true);
	if (!col0 || !col1)
		return (false);
	return (fabs(col0->x - col1->x) <= DBL_EPSILON
			&& fabs(col0->y - col1->y) <= DBL_EPSILON
			&& fabs(col0->z - col1->z) <= DBL_EPSILON
			&& col0->w == col1->w);
}
