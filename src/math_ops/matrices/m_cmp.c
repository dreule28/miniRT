#include "mini_rt.h"

bool	m_cmp(void *matrix1, void *matrix2, int size)
{
	if (size == 2)
		return (m2_cmp((t_m2 *)matrix1, (t_m2 *)matrix2));
	else if (size == 3)
		return (m3_cmp((t_m3 *)matrix1, (t_m3 *)matrix2));
	else if (size == 4)
		return (m4_cmp((t_m4 *)matrix1, (t_m4 *)matrix2));
	return (false);
}

bool	m4_cmp(t_m4 *matrix1, t_m4 *matrix2)
{
	t_m4_col	*curr1;
	t_m4_col	*curr2;

	if (!matrix1 || !matrix2)
		return (false);
	curr1 = matrix1->head;
	curr2 = matrix2->head;
	while (curr1 && curr2)
	{
		if (fabs(curr1->x - curr2->x) > DBL_EPSILON
			|| fabs(curr1->y - curr2->y) > DBL_EPSILON
			|| fabs(curr1->z - curr2->z) > DBL_EPSILON
			|| fabs(curr1->w - curr2->w) > DBL_EPSILON)
			return (false);
		curr1 = curr1->next;
		curr2 = curr2->next;
	}
	if (curr1 || curr2)
		return (false);
	return (true);
}

bool	m3_cmp(t_m3 *matrix1, t_m3 *matrix2)
{
	t_m3_col	*curr1;
	t_m3_col	*curr2;

	if (!matrix1 || !matrix2)
		return (false);
	curr1 = matrix1->head;
	curr2 = matrix2->head;
	while (curr1 && curr2)
	{
		if (fabs(curr1->x - curr2->x) > DBL_EPSILON
			|| fabs(curr1->y - curr2->y) > DBL_EPSILON
			|| fabs(curr1->z - curr2->z) > DBL_EPSILON)
			return (false);
		curr1 = curr1->next;
		curr2 = curr2->next;
	}
	if (curr1 || curr2)
		return (false);
	return (true);
}

bool	m2_cmp(t_m2 *matrix1, t_m2 *matrix2)
{
	t_m2_col	*curr1;
	t_m2_col	*curr2;

	if (!matrix1 || !matrix2)
		return (false);
	curr1 = matrix1->head;
	curr2 = matrix2->head;
	while (curr1 && curr2)
	{
		if (fabs(curr1->x - curr2->x) > DBL_EPSILON
			|| fabs(curr1->y - curr2->y) > DBL_EPSILON)
			return (false);
		curr1 = curr1->next;
		curr2 = curr2->next;
	}
	if (curr1 || curr2)
		return (false);
	return (true);
}
