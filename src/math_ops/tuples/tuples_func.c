#include "mini_rt.h"

bool	ftm_tup_cmp(t_tuples tuples1, t_tuples tuples2)
{
	if (tuples1.w != tuples2.w)
		return (true);
	else if (fabs(tuples1.x - tuples2.x) > DBL_EPSILON)
		return (true);
	else if (fabs(tuples1.y - tuples2.y) > DBL_EPSILON)
		return (true);
	else if (fabs(tuples1.z - tuples2.z) > DBL_EPSILON)
		return (true);
	return (false);
}

void	ftm_tup_add(t_tuples *new_tup, t_tuples tup1, t_tuples tup2)
{
	new_tup->x = tup1.x + tup2.x;
	new_tup->y = tup1.y + tup2.y;
	new_tup->z = tup1.z + tup2.z;
	new_tup->w = tup1.w + tup2.w;
}

void	ftm_tup_subtract(t_tuples *new_tup, t_tuples tup1, t_tuples tup2)
{
	new_tup->x = tup1.x - tup2.x;
	new_tup->y = tup1.y - tup2.y;
	new_tup->z = tup1.z - tup2.z;
	new_tup->w = tup1.w - tup2.w;
}

void	ftm_tup_negate(t_tuples *new_tuples)
{
	new_tuples->x *= -1;
	new_tuples->y *= -1;
	new_tuples->z *= -1;
	new_tuples->w *= -1;
}
