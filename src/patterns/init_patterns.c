#include "mini_rt.h"

void	stripe_pattern(t_pattern *pattern, t_rgb color1, t_rgb color2)
{
	pattern->color1 = color1;
	pattern->color2 = color2;
	pattern->type = STRIPE_PATTERN;
	pattern->has_pattern = true;
}

void	gradient_pattern(t_pattern *pattern, t_rgb color1, t_rgb color2)
{
	pattern->color1 = color1;
	pattern->color2 = color2;
	pattern->type = GRADIENT_PATTERN;
	pattern->has_pattern = true;
}

void	ring_pattern(t_pattern *pattern, t_rgb color1, t_rgb color2)
{
	pattern->color1 = color1;
	pattern->color2 = color2;
	pattern->type = RING_PATTERN;
	pattern->has_pattern = true;
}

void	checkers_pattern(t_pattern *pattern, t_rgb color1, t_rgb color2)
{
	pattern->color1 = color1;
	pattern->color2 = color2;
	pattern->type = CHECKERS_PATTERN;
	pattern->has_pattern = true;
}
