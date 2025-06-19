#include "mini_rt.h"

t_m2_col	*add_m2_col(t_m2 *m2, double x, double y)
{
	t_m2_col	*new_col;

	new_col = malloc(sizeof(t_m2_col));
	if (!new_col)
		return (NULL);
	new_col->x = x;
	new_col->y = y;
	new_col->next = NULL;
	if (!m2->head)
		m2->head = new_col;
	else
		m2->tail->next = new_col;
	m2->tail = new_col;
	m2->size++;
	return (new_col);
}

t_m3_col	*add_m3_col(t_m3 *m3, double x, double y, double z)
{
	t_m3_col	*new_col;

	new_col = malloc(sizeof(t_m3_col));
	if (!new_col)
		return (NULL);
	new_col->x = x;
	new_col->y = y;
	new_col->z = z;
	new_col->next = NULL;
	if (!m3->head)
		m3->head = new_col;
	else
		m3->tail->next = new_col;
	m3->tail = new_col;
	m3->size++;
	return (new_col);
}

t_m4_col	*add_m4_col(double x, double y, double z, double w)
{
	t_m4_col	*new_col;

	new_col = malloc(sizeof(t_m4_col));
	if (!new_col)
		return (NULL);
	new_col->x = x;
	new_col->y = y;
	new_col->z = z;
	new_col->w = w;
	new_col->next = NULL;
	return (new_col);
}

void	append_col(t_m4 *m4, t_m4_col *new_col)
{
	if (!m4->head)
	{
		m4->head = new_col;
		m4->tail = new_col;
	}
	else
	{
		m4->tail->next = new_col;
		m4->tail = new_col;
	}
	m4->size++;
	new_col->next = NULL;
}
