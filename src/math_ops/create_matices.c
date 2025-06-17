#include "mini_rt.h"

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

t_m3_row	*create_m3_row(double x, double y, double z)
{
	t_m3_row	*new_row;

	new_row = ft_calloc(1, sizeof(t_m3_row));
	if (!new_row)
		return (NULL);
	new_row->x = x;
	new_row->y = y;
	new_row->z = z;
	new_row->next = NULL;
	return (new_row);
}

t_m2_row	*create_m2_row(double x, double y)
{
	t_m2_row	*new_row;

	new_row = ft_calloc(1, sizeof(t_m2_row));
	if (!new_row)
		return (NULL);
	new_row->x = x;
	new_row->y = y;
	new_row->next = NULL;
	return (new_row);
}

