#include "mini_rt.h"

bool	set_intersection_to_obj(t_scene *scene, t_obj_node *curr)
{
	// setup_camera_fov(scene);
	if (curr->type == SPHERE)
		if(!setup_intersec_sphere(scene, curr))
			return(false);
	return(true);
}
