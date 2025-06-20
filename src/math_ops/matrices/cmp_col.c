#include "mini_rt.h"

bool	cmp_m2_col(t_m2_col *col1, t_m2_col *col2)
{
	if (!col1 && !col2)
		return (true);
	if (!col1 || !col2)
		return (false);
	return (fabs(col1->x - col2->x) <= DBL_EPSILON
			&& fabs(col1->y - col2->y) <= DBL_EPSILON);
}

bool	cmp_m3_col(t_m3_col *col1, t_m3_col *col2)
{
	if (!col1 && !col2)
		return (true);
	if (!col1 || !col2)
		return (false);
	return (fabs(col1->x - col2->x) <= DBL_EPSILON
			&& fabs(col1->y - col2->y) <= DBL_EPSILON
			&& fabs(col1->z - col2->z) <= DBL_EPSILON);
}

bool	cmp_m4_col(t_m4_col *col1, t_m4_col *col2)
{
	if (!col1 && !col2)
		return (true);
	if (!col1 || !col2)
		return (false);
	return (fabs(col1->x - col2->x) <= DBL_EPSILON
			&& fabs(col1->y - col2->y) <= DBL_EPSILON
			&& fabs(col1->z - col2->z) <= DBL_EPSILON
			&& col1->w == col2->w);
}
