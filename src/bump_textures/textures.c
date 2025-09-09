#include "mini_rt.h"

void	bump_sine(t_tuples *out, double amp, t_tuples p)
{
	double	f;

	// ripples along Y from XZ coords
	f = 10.0;
	init_vector(out, amp * 0.0, amp * sin(f * p.x) * cos(f * p.z), amp * 0.0);
}

void	bump_quilt(t_tuples *out, double amp, t_tuples p)
{
	double	f;
	f = 8.0;
	double	sx = sin(f * p.x), cx;
	double	sy = sin(f * p.y), cy;
	double	sz = sin(f * p.z), cz;

	sx = sin(f * p.x), cx = cos(f * p.x);
	sy = sin(f * p.y), cy = cos(f * p.y);
	sz = sin(f * p.z), cz = cos(f * p.z);
	init_vector(out, amp * sx * cy, amp * sy * cz, amp * cx * sz);
}

void	bump_checkers(t_tuples *out, double amp, t_tuples p)
{
	int		sum;
	double	sign;

	sum = (int)floor(p.x) + (int)floor(p.y) + (int)floor(p.z);
	sign = (sum % 2 == 0) ? 1.0 : -1.0;
	init_vector(out, 0.0, amp * 0.5 * sign, 0.0);
}

void	bump_wave(t_tuples *out, double amp, t_tuples p)
{
	double	f;
	double	g;

	f = 12.0;
	g = sin(f * (p.x + p.z));
	init_vector(out, amp * g, amp * 0.25 * g, amp * g);
}
