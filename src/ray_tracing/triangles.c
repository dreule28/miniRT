#include "mini_rt.h"

bool	intersect_triangle(t_obj_node *node, t_ray ray)
{
	t_tri_inter	t;

	ftm_tup_cross(&t.dir_cross_e2, ray.direction, node->data->triangle->e2);
	t.det = ftm_tup_dot(node->data->triangle->e1, t.dir_cross_e2);
	if (fabs(t.det) < EPSILON)
		return (false);
	t.f = 1.0 / t.det;
	ftm_tup_subtract(&t.p1_to_origin, ray.origin, node->data->triangle->p1);
	t.u = t.f * ftm_tup_dot(t.p1_to_origin, t.dir_cross_e2);
	if (t.u < 0.0 || t.u > 1.0)
		return (false);
	ftm_tup_cross(&t.origin_cross_e1, t.p1_to_origin, node->data->triangle->e1);
	t.v = t.f * ftm_tup_dot(ray.direction, t.origin_cross_e1);
	if (t.v < 0.0 || (t.u + t.v) > 1.0)
		return (false);
	node->t[0] = t.f * ftm_tup_dot(node->data->triangle->e2, t.origin_cross_e1);
	node->has_intersection = true;
	return (true);
}
