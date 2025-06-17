#include "mini_rt.h"

t_m4_col	*create_m4_col(double x, double y, double z, double w)
{
	t_m4_col	*new_col;

	new_col = ft_calloc(1, sizeof(t_m4_col));
	if (!new_col)
		return (NULL);
	new_col->x = x;
	new_col->y = y;
	new_col->z = z;
	new_col->w = w;
	new_col->next = NULL;
	return (new_col);
}

t_m3_col	*create_m3_col(double x, double y, double z)
{
	t_m3_col	*new_col;

	new_col = ft_calloc(1, sizeof(t_m3_col));
	if (!new_col)
		return (NULL);
	new_col->x = x;
	new_col->y = y;
	new_col->z = z;
	new_col->next = NULL;
	return (new_col);
}

t_m2_col	*create_m2_col(double x, double y)
{
	t_m2_col	*new_col;

	new_col = ft_calloc(1, sizeof(t_m2_col));
	if (!new_col)
		return (NULL);
	new_col->x = x;
	new_col->y = y;
	new_col->next = NULL;
	return (new_col);
}

