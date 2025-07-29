#include "mini_rt.h"

t_pattern	*stripe_pattern(t_rgb *color1, t_rgb *color2)
{
	t_pattern	*new_pattern;

	new_pattern = ft_calloc(sizeof(t_pattern), 1);
	new_pattern->color1 = color1;
	new_pattern->color2 = color2;
	return (new_pattern);
}

t_rgb	*stripe_at(t_pattern *pattern, t_tuples *point)
{
	double floor_x;

	floor_x = floor(point->x);
	if (fmod(floor_x, 2) == 0)
		return (pattern->color1);
	else
		return (pattern->color2);
}
