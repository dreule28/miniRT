#include "mini_rt.h"

bool	comps_equal(t_computations a, t_computations b)
{
	return (fabs(a.point.x - b.point.x) < DBL_EPSILON &&
			fabs(a.point.y - b.point.y) < DBL_EPSILON &&
			fabs(a.point.z - b.point.z) < DBL_EPSILON &&
			fabs(a.eyev.x - b.eyev.x) < DBL_EPSILON &&
			fabs(a.eyev.y - b.eyev.y) < DBL_EPSILON &&
			fabs(a.eyev.z - b.eyev.z) < DBL_EPSILON);
}

t_material	get_material_from_comps(t_computations comps, t_obj_list *obj_list)
{
	t_obj_node	*curr;

	curr = obj_list->head;
	while (curr)
	{
		if (comps_equal(curr->comp, comps))
		{
			if (curr->type == PLANE)
				return (curr->data->plane->material);
			else if (curr->type == SPHERE)
				return (curr->data->sphere->material);
			else if (curr->type == CYLINDER)
				return (curr->data->cylinder->material);
			else if (curr->type == CUBE)
				return (curr->data->cube->material);
			else if (curr->type == CONE)
				return (curr->data->cone->material);
		}
		curr = curr->next;
	}
	return (get_material());
}
