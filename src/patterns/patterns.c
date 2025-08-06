#include "mini_rt.h"

t_rgb	*stripe_at(t_pattern *pattern, t_tuples *point)
{
	double	floor_x;

	floor_x = floor(point->x);
	if (fmod(floor_x, 2) == 0)
		return (pattern->color1);
	else
		return (pattern->color2);
}

t_rgb	*gradient_at(t_pattern *pattern, t_tuples *point)
{
	t_rgb	*distance;
	t_rgb	*result;
	double	fraction;

	distance = init_rgb(pattern->color2->r - pattern->color1->r,
			pattern->color2->g - pattern->color1->g, pattern->color2->b
			- pattern->color1->b);
	fraction = point->x - floor(point->x);
	result = init_rgb(pattern->color1->r + distance->r * fraction,
			pattern->color1->g + distance->g * fraction, pattern->color1->b
			+ distance->b * fraction);
	return (result);
}

t_rgb	*ring_at(t_pattern *pattern, t_tuples *point)
{
	double	distance;
	int		ring_number;

	distance = sqrt(point->x * point->x + point->z * point->z);
	ring_number = (int)floor(distance);
	if (ring_number % 2 == 0)
		return (pattern->color1);
	else
		return (pattern->color2);
}

t_rgb	*checkers_at(t_pattern *pattern, t_tuples *point)
{
	int	sum;

	sum = (int)floor(point->x) + (int)floor(point->y) + (int)floor(point->z);
	if (sum % 2 == 0)
		return (pattern->color1);
	else
		return (pattern->color2);
}

t_rgb	*test_pattern_at(t_pattern *pattern, t_tuples *point)
{
	(void)pattern;
	return (init_rgb(point->x, point->y, point->z));
}
