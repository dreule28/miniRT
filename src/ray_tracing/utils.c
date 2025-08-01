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
		}
		curr = curr->next;
	}
	return (get_material());
}

t_obj_node	*create_inter_node(t_obj_node *old_node, double t)
{
	t_obj_node	*new_node;

	new_node = ft_calloc(sizeof(t_obj_node), 1);
	if (!new_node)
		return (NULL);
	new_node->type = old_node->type;
	new_node->data = old_node->data;
	new_node->matrix = old_node->matrix;
	new_node->t = ft_calloc(sizeof(double), 2);
	if (!new_node->t)
		return (free(new_node), NULL);
	new_node->t[0] = t;
	new_node->t[1] = t;
	new_node->comp = ft_calloc(sizeof(t_computations), 1);
	if (!new_node->comp)
		return (free(new_node->t), free(new_node), NULL);
	new_node->next = NULL;
	return (new_node);
}
