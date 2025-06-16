#include "mini_rt.h"



bool	mat_cmp(t_m4 *matrice1, t_m4 *matrice2)
{
	t_m4_row *current1;
	t_m4_row *current2;

	current1 = matrice1->row1;
	current2 = matrice2->row1;
	while (current1 != NULL)
	{
		if (fabs(current1->x - current2->x) > DBL_EPSILON || fabs(current1->y
				- current2->y) > DBL_EPSILON || fabs(current1->z
				- current2->z) > DBL_EPSILON || fabs(current1->w
				- current2->w) > DBL_EPSILON)
			return (false);
		current1 = current1->next;
		current2 = current2->next;
	}
	if (current1 != NULL || current2 != NULL)
		return (false);
	return (true);
}