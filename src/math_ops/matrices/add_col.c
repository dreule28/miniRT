#include "mini_rt.h"

void	assign_m2_col(t_m2_col *new_col, double x, double y)
{
	new_col->x = x;
	new_col->y = y;
}

void	assign_m3_col(t_m3_col *new_col, double x, double y, double z)
{
	new_col->x = x;
	new_col->y = y;
	new_col->z = z;
}

void	assign_m4_col(t_m4_col *new_col, t_m4_col values)
{
	new_col->x = values.x;
	new_col->y = values.y;
	new_col->z = values.z;
	new_col->w = values.w;
}
