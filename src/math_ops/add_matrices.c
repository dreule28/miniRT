#include "mini_rt.h"

bool	add_row_m4(t_m4 *m4, t_m4_row *new_row)
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

bool	add_row_m3(t_m3 *m3, t_m3_row *new_row)
{
	if (!m3 || !new_row)
		return (false);
	if (!m3->row1)
		m3->row1 = new_row;
	else if (!m3->row2)
	{
		m3->row2 = new_row;
		m3->row1->next = m3->row2;
	}
	else if (!m3->row3)
	{
		m3->row3 = new_row;
		m3->row2->next = m3->row3;
	}
	else
	{
		free(new_row);
		return (false);
	}
	return (true);
}

bool	add_row_m2(t_m2 *m2, t_m2_row *new_row)
{
	if (!m2 || !new_row)
		return (false);
	if (!m2->row1)
		m2->row1 = new_row;
	else if (!m2->row2)
	{
		m2->row2 = new_row;
		m2->row1->next = m2->row2;
	}
	else
	{
		free(new_row);
		return (false);
	}
	return (true);
}
