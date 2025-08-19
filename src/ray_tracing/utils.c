#include "mini_rt.h"

t_material	get_material_from_comps(t_computations *comps, t_obj_list *obj_list)
{
	t_obj_node	*curr;

	curr = obj_list->head;
	while (curr)
	{
		if (curr->comp == comps)
		{
			if (curr->type == PLANE)
				return (curr->data->plane->material);
			else if (curr->type == SPHERE)
				return (curr->data->sphere->material);
			else if (curr->type == CYLINDER)
				return (curr->data->cylinder->material);
			else if (curr->type == CUBE)
				return (curr->data->cube->material);
		}
		curr = curr->next;
	}
	return (get_material());
}
