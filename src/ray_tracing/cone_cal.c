#include "mini_rt.h"

bool	cone_intersec_cal(t_obj_node *node, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	double	discri;

	a = ray.direction.x * ray.direction.x - ray.direction.y * ray.direction.y
		+ ray.direction.z * ray.direction.z;
	b = 2.0 * ray.origin.x * ray.direction.x - 2.0 * ray.origin.y
		* ray.direction.y + 2.0 * ray.origin.z * ray.direction.z;
	c = ray.origin.x * ray.origin.x - ray.origin.y * ray.origin.y + ray.origin.z
		* ray.origin.z;
	discri = b * b - 4 * a * c;
	if (fabs(a) < DBL_EPSILON)
	{
		if (fabs(b) < DBL_EPSILON)
			return (false);
		node->t[0] = -c / (2.0 * b);
		node->t[1] = node->t[0];
		return (true);
	}
	if (discri < 0.0)
		return (false);
	node->t[0] = (-b - sqrtf(discri)) / (2 * a);
	node->t[1] = (-b + sqrtf(discri)) / (2 * a);
	return (true);
}

int	check_cone_height(t_obj_node *node, t_ray ray, t_cone cone)
{
	double	t0;
	double	t1;
	double	y0;
	double	y1;
	int		count;

	t0 = node->t[0];
	t1 = node->t[1];
	if (t0 > t1)
		swap_value(&t0, &t1);
	y0 = ray.origin.y + t0 * ray.direction.y;
	y1 = ray.origin.y + t1 * ray.direction.y;
	count = 0;
	if (cone.minimum < y0 && y0 < cone.maximum)
		node->t[count++] = t0;
	if (cone.minimum < y1 && y1 < cone.maximum)
		node->t[count++] = t1;
	if (count == 1)
		node->t[1] = node->t[0];
	return (count);
}

bool	intersect_cone(t_obj_node *node, t_ray ray, t_cone cone)
{
	int		count;
	double	tmp;

	if (!cone_intersec_cal(node, ray))
	{
		node->has_intersection = false;
		return (false);
	}
	count = check_cone_height(node, ray, cone);
	if (count == 0)
	{
		node->has_intersection = false;
		return (false);
	}
	if (node->t[0] > node->t[1])
	{
		tmp = node->t[0];
		node->t[0] = node->t[1];
		node->t[1] = tmp;
	}
	node->has_intersection = true;
	return (true);
}

void	local_cone(t_tuples *normal, t_obj_node curr, t_tuples p)
{
	double	y;

	if (curr.data->cone->closed)
	{
		if (fabs(p.y - curr.data->cone->maximum) < EPSILON)
		{
			init_vector(normal, 0, 1, 0);
			return ;
		}
		if (fabs(p.y - curr.data->cone->minimum) < EPSILON)
		{
			init_vector(normal, 0, -1, 0);
			return ;
		}
	}
	y = sqrt(p.x * p.x + p.z * p.z);
	if (p.y > 0)
		y = -y;
	init_vector(normal, p.x, y, p.z);
}
