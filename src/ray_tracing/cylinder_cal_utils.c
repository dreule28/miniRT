#include "mini_rt.h"

void	swap_value(double *t0, double *t1)
{
	double	tmp;

	tmp = *t0;
	*t0 = *t1;
	*t1 = tmp;
}

bool	check_sides(double caps[2], t_obj_node *node, int cap_count)
{
	int		i;
	double	best_cap;

	best_cap = INFINITY;
	i = 0;
	while (i < cap_count)
	{
		if (caps[i] > 0.0 && caps[i] < best_cap)
			best_cap = caps[i];
		i++;
	}
	if (best_cap < INFINITY)
	{
		node->t[1] = best_cap;
		if (node->t[0] > node->t[1])
			swap_value(&node->t[0], &node->t[1]);
		return (node->has_intersection = true, true);
	}
	else
	{
		node->t[1] = node->t[0];
		return (node->has_intersection = true, true);
	}
	return (false);
}
