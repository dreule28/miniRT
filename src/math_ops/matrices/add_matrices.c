#include "mini_rt.h"

bool	add_col_m4(t_m4 *m4, t_m4_col *new_col)
{
	if (!m4 || !new_col)
		return (false);
	if (!m4->col1)
		m4->col1 = new_col;
	else if (!m4->col2)
	{
		m4->col2 = new_col;
		m4->col1->next = m4->col2;
	}
	else if (!m4->col3)
	{
		m4->col3 = new_col;
		m4->col2->next = m4->col3;
	}
	else if (!m4->col4)
	{
		m4->col4 = new_col;
		m4->col3->next = m4->col4;
	}
	else
	{
		free(new_col);
		return (false);
	}
	return (true);
}

bool	add_col_m3(t_m3 *m3, t_m3_col *new_col)
{
	if (!m3 || !new_col)
		return (false);
	if (!m3->col1)
		m3->col1 = new_col;
	else if (!m3->col2)
	{
		m3->col2 = new_col;
		m3->col1->next = m3->col2;
	}
	else if (!m3->col3)
	{
		m3->col3 = new_col;
		m3->col2->next = m3->col3;
	}
	else
	{
		free(new_col);
		return (false);
	}
	return (true);
}

bool	add_col_m2(t_m2 *m2, t_m2_col *new_col)
{
	if (!m2 || !new_col)
		return (false);
	if (!m2->col1)
		m2->col1 = new_col;
	else if (!m2->col2)
	{
		m2->col2 = new_col;
		m2->col1->next = m2->col2;
	}
	else
	{
		free(new_col);
		return (false);
	}
	return (true);
}
