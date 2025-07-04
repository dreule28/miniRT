#include "mini_rt.h"

t_tuples	*init_vector(double x, double y, double z)
{
	t_tuples	*vector;

	vector = ft_calloc(1, sizeof(t_tuples));
	if (!vector)
		return (NULL);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	vector->w = VECTOR;
	return (vector);
}

t_tuples	*init_point(double x, double y, double z)
{
	t_tuples	*point;

	point = ft_calloc(1, sizeof(t_tuples));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	point->w = POINT;
	return (point);
}

t_rgb	*init_rgb(double r, double g, double b)
{
	t_rgb	*rgb;

	rgb = ft_calloc(1, sizeof(t_rgb));
	if (!rgb)
		return (NULL);
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
	return (rgb);
}
