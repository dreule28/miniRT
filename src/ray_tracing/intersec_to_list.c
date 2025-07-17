#include "mini_rt.h"

bool	set_intersection_to_obj(t_scene *scene, t_obj_node *curr, t_ray *ray)
{
	if (curr->type == SPHERE)
		if (!setup_intersec_sphere(scene, curr, ray))
			return (false);
	if (curr->type == PLANE)
		if (!setup_intersec_plane(scene, curr,ray))
			return (false);
	return (true);
}
