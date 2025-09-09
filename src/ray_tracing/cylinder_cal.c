#include "mini_rt.h"

bool	check_cap(t_ray ray, double t)
{
	double	x;
	double	z;
	double	result;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	result = (x * x + z * z);
	if (result <= 1.0 + DBL_EPSILON)
		return (true);
	return (false);
}

int	intersect_caps(t_ray ray, t_cylinder cylinder, double *out)
{
	int		count;
	double	t;
	double	tmp;

	count = 0;
	if (!cylinder.closed)
		return (0);
	if (fabs(ray.direction.y) < DBL_EPSILON)
		return (0);
	t = (cylinder.minimum - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
		out[count++] = t;
	t = (cylinder.maximum - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
		out[count++] = t;
	if (count == 2 && out[0] > out[1])
	{
		tmp = out[0];
		out[0] = out[1];
		out[1] = tmp;
	}
	if (count == 1)
		out[1] = out[0];
	return (count);
}

bool	cylinder_intersec_cal(t_obj_node *node, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	double	discri;

	a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
	if (fabs(a) < DBL_EPSILON)
		return (false);
	b = (2 * ray.origin.x * ray.direction.x) + (2 * ray.origin.z
			* ray.direction.z);
	c = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z - 1;
	discri = b * b - 4 * a * c;
	if (discri < 0.0)
		return (false);
	node->t[0] = (-b - sqrtf(discri)) / (2 * a);
	node->t[1] = (-b + sqrtf(discri)) / (2 * a);
	return (true);
}

int	check_cylinder_height(t_obj_node *node, t_ray ray, t_cylinder cylinder)
{
	double	t0;
	double	t1;
	double	y0;
	double	y1;
	int		count;

	t0 = node->t[0];
	t1 = node->t[1];
	if (t0 > t1)
		swap_values(t0, t1);
	y0 = ray.origin.y + t0 * ray.direction.y;
	y1 = ray.origin.y + t1 * ray.direction.y;
	count = 0;
	if (cylinder.minimum < y0 && y0 < cylinder.maximum)
		node->t[count++] = t0;
	if (cylinder.minimum < y1 && y1 < cylinder.maximum)
		node->t[count++] = t1;
	if (count == 1)
		node->t[1] = node->t[0];
	return (count);
}

bool	cylinder_cap_cal(t_obj_node *node, t_ray ray, t_cylinder cylinder)
{
	double	caps[2];
	int		count;

	count = intersect_caps(ray, cylinder, caps);
	if (count == 0)
		return (false);
	node->t[0] = caps[0];
	node->t[1] = caps[1];
	return (true);
}
