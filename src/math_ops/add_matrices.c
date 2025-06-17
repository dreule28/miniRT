#include "mini_rt.h"

void	add_m4_row(t_m4 *m4)
{
	t_m4_row *m4_row;

	m4_row = ft_calloc(1, sizeof(m4_row));
	if(!m4_row)
		return(NULL);
	m4_row->x = 0;
	m4_row->y = 0;
	m4_row->z = 0;
	m4_row->w = 0;
	m4_row->next = NULL;
	
}