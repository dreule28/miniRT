#include "mini_rt.h"

bool	m_cmp(void *matrice1, void *matrice2, int size)
{
	if (size == 2)
		return (m2_cmp((t_m2 *)matrice1, (t_m2 *)matrice2));
	else if (size == 3)
		return (m3_cmp((t_m3 *)matrice1, (t_m3 *)matrice2));
	else if (size == 4)
		return (m4_cmp((t_m4 *)matrice1, (t_m4 *)matrice2));
	return (false);
}

bool	m4_cmp(t_m4 *matrice1, t_m4 *matrice2)
{
	t_m4_col	*current1;
	t_m4_col	*current2;

	if (!matrice1 || !matrice2)
		return (false);
	current1 = matrice1->col1;
	current2 = matrice2->col1;
	while (current1 != NULL && current2 != NULL)
	{
		if (fabs(current1->x - current2->x) > DBL_EPSILON)
			return (false);
		else if (fabs(current1->y - current2->y) > DBL_EPSILON)
			return (false);
		else if (fabs(current1->z - current2->z) > DBL_EPSILON)
			return (false);
		else if (fabs(current1->w - current2->w) > DBL_EPSILON)
			return (false);
		current1 = current1->next;
		current2 = current2->next;
	}
	if (current1 != NULL || current2 != NULL)
		return (false);
	return (true);
}

bool	m3_cmp(t_m3 *matrice1, t_m3 *matrice2)
{
	t_m3_col	*current1;
	t_m3_col	*current2;

	if (!matrice1 || !matrice2)
		return (false);
	current1 = matrice1->col1;
	current2 = matrice2->col1;
	while (current1 != NULL && current2 != NULL)
	{
		if (fabs(current1->x - current2->x) > DBL_EPSILON)
			return (false);
		else if (fabs(current1->y - current2->y) > DBL_EPSILON)
			return (false);
		else if (fabs(current1->z - current2->z) > DBL_EPSILON)
			return (false);
		current1 = current1->next;
		current2 = current2->next;
	}
	if (current1 != NULL || current2 != NULL)
		return (false);
	return (true);
}

bool	m2_cmp(t_m2 *matrice1, t_m2 *matrice2)
{
	t_m2_col	*current1;
	t_m2_col	*current2;

	if (!matrice1 || !matrice2)
		return (false);
	current1 = matrice1->col1;
	current2 = matrice2->col1;
	while (current1 != NULL && current2 != NULL)
	{
		if (fabs(current1->x - current2->x) > DBL_EPSILON)
			return (false);
		else if (fabs(current1->y - current2->y) > DBL_EPSILON)
			return (false);
		current1 = current1->next;
		current2 = current2->next;
	}
	if (current1 != NULL || current2 != NULL)
		return (false);
	return (true);
}