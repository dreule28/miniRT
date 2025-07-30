#include "mini_rt.h"

bool	obj_is_in_container(t_obj_node **container, int size, t_obj_node *obj)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (container[i]->data == obj->data)
			return (true);
		i++;
	}
	return (false);
}

int	remove_object(t_obj_node **container, int size, t_obj_node *obj)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if (container[i]->data != obj->data)
		{
			container[j] = container[i];
			j++;
		}
		i++;
	}
	return (j);
}

void	handle_hit_n1(t_obj_node **containers, t_obj_list *intersections,
			t_obj_node *curr, int size)
{
	if (size == 0)
		curr->comp->n1 = 1.0;
	else
		curr->comp->n1 = get_material_from_comps(
							containers[size - 1]->comp,
							intersections).refractive_index;
}

void	handle_hit_n2(t_obj_node **containers, t_obj_list *intersections,
			t_obj_node *curr, int size)
{
	if (size == 0)
		curr->comp->n2 = 1.0;
	else
		curr->comp->n2 = get_material_from_comps(
							containers[size - 1]->comp,
							intersections).refractive_index;
}

void	calculate_refractive(t_obj_list *intersections, t_obj_node *hit)
{
	t_obj_node	*containers[16];
	t_obj_node	*curr;
	int			size;

	curr = intersections->head;
	size = 0;
	while (curr)
	{
		if (curr == hit)
			handle_hit_n1(containers, intersections, curr, size);
		if (obj_is_in_container(containers, size, curr))
			size = remove_object(containers, size, curr);
		else
		{
			containers[size] = curr;
			size++;
		}
		if (curr == hit)
		{
			handle_hit_n2(containers, intersections, curr, size);
			break;
		}
		curr = curr->next;
	}
}
