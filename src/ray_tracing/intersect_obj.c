#include "mini_rt.h"

double	discri(t_ray ray, t_sphere sphere, double *a, double *b)
{
	t_tuples	sphere_center;
	t_tuples	sphere_to_ray;
	double		discriminant;
	double		c;

	copy_point(&sphere_center, sphere.pos);
	ftm_tup_subtract(&sphere_to_ray, ray.origin, sphere_center);
	*a = ftm_tup_dot(ray.direction, ray.direction);
	*b = 2 * ftm_tup_dot(ray.direction, sphere_to_ray);
	c = ftm_tup_dot(sphere_to_ray, sphere_to_ray) - (sphere.radius
			* sphere.radius);
	discriminant = *b * *b - 4 * *a * c;
	return (discriminant);
}

bool	intersect_sphere(t_obj_node *node, t_ray ray, t_sphere sphere)
{
	double	a;
	double	b;
	double	discriminant;

	discriminant = discri(ray, sphere, &a, &b);
	if (discriminant < 0.0)
	{
		node->has_intersection = false;
		return (false);
	}
	node->t[0] = (-b - sqrt(discriminant)) / (2 * a);
	node->t[1] = (-b + sqrt(discriminant)) / (2 * a);
	node->has_intersection = true;
	return (true);
}

bool	intersect_plane(t_obj_node *node, t_ray ray)
{
	double	intersec;

	if (fabs(ray.direction.y) < DBL_EPSILON)
	{
		node->has_intersection = false;
		return (false);
	}
	intersec = -ray.origin.y / ray.direction.y;
	if (intersec <= 0.0)
	{

		node->has_intersection = false;
		return (false);
	}
	node->t[0] = intersec;
	node->t[1] = intersec;
	node->has_intersection = true;
	return (true);
}

bool	intersect_cylinder(t_obj_node *node, t_ray ray, t_cylinder cylinder)
{
	int		side_count;
	double	caps[2];
	int		cap_count;

	if (!cylinder_intersec_cal(node, ray))
		side_count = 0;
	else
		side_count = check_cylinder_height(node, ray, cylinder);
	cap_count = intersect_caps(ray, cylinder, caps);
	if (side_count == 2)
		return (node->has_intersection = true,true);
	if (side_count == 1)
	{
		if(check_sides(caps, node, cap_count))
			return(true);
	}
	if (cap_count > 0)
	{
		node->t[0] = caps[0];
		node->t[1] = caps[1];
		node->has_intersection = true;
		return (true);
	}
	return (node->has_intersection = false, false);
}
