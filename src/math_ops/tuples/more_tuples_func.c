#include "mini_rt.h"

void	ftm_tup_mult(t_tuples *new_tuples, t_tuples in, double value)
{
	new_tuples->x = in.x * value;
	new_tuples->y = in.y * value;
	new_tuples->z = in.z * value;
	new_tuples->w = in.w * value;
}

void	ftm_rgb_mult(t_rgb *new_rgb, t_rgb in, double value)
{
	new_rgb->r = in.r * value;
	new_rgb->g = in.g * value;
	new_rgb->b = in.b * value;
}

void	ftm_tup_divied(t_tuples *new_tup, t_tuples *tuples, double value)
{
	if (value == 0)
		return ;
	new_tup->x = tuples->x / value;
	new_tup->y = tuples->y / value;
	new_tup->z = tuples->z / value;
	new_tup->w = tuples->w / value;
}

double	magnitude_vector(t_tuples vector)
{
	double	sum;
	double	magnitude;

	sum = 0;
	sum += vector.x * vector.x;
	sum += vector.y * vector.y;
	sum += vector.z * vector.z;
	magnitude = sqrt(sum);
	return (magnitude);
}

void	ftm_tup_norm(t_tuples *new_vector, t_tuples in)
{
	double	mag;

	mag = magnitude_vector(in);
	new_vector->x = in.x / mag;
	new_vector->y = in.y / mag;
	new_vector->z = in.z / mag;
}
