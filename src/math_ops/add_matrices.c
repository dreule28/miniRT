#include "mini_rt.h"

bool	add_row_to_m4(t_m4 *m4, t_m4_row *new_row)
{
	if (!m4 || !new_row)
		return (false);
	if (!m4->row1)
		m4->row1 = new_row;
	else if (!m4->row2)
	{
		m4->row2 = new_row;
		m4->row1->next = m4->row2;
	}
	else if (!m4->row3)
	{
		m4->row3 = new_row;
		m4->row2->next = m4->row3;
	}
	else if (!m4->row4)
	{
		m4->row4 = new_row;
		m4->row3->next = m4->row4;
	}
	else
	{
		free(new_row);
		return (false);
	}
	return (true);
}

t_m4_row	*create_m4_row(double x, double y, double z, double w)
{
	t_m4_row	*new_row;

	new_row = ft_calloc(1, sizeof(t_m4_row));
	if (!new_row)
		return (NULL);
	new_row->x = x;
	new_row->y = y;
	new_row->z = z;
	new_row->w = w;
	new_row->next = NULL;
	return (new_row);
}
