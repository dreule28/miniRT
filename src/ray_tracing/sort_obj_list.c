#include "mini_rt.h"

bool	should_swap_nodes(t_obj_node *curr, t_obj_node *next)
{
	if (!curr->t && next->t)
		return (true);
	if (curr->t && !next->t)
		return (false);
	if (!curr->t && !next->t)
		return (false);
	if (curr->t && next->t)
		return (curr->t[0] > next->t[0]);
	return (false);
}

void	swap_nodes(t_obj_list *obj_list, t_obj_node *prev, t_obj_node *curr,
		t_obj_node *next)
{
	curr->next = next->next;
	next->next = curr;
	if (prev)
		prev->next = next;
	else
		obj_list->head = next;
	if (curr->next == NULL)
		obj_list->tail = curr;
}

void	swap_pointers(t_obj_node **curr, t_obj_node **prev)
{
	*prev = *curr;
	*curr = (*curr)->next;
}

t_obj_list	*sort_obj_list(t_obj_list *obj_list)
{
	t_obj_node	*prev;
	t_obj_node	*curr;
	t_obj_node	*next;
	bool		swapped;

	swapped = true;
	while (swapped)
	{
		swapped = false;
		prev = NULL;
		curr = obj_list->head;
		while (curr && curr->next)
		{
			next = curr->next;
			if (should_swap_nodes(curr, next))
			{
				swap_nodes(obj_list, prev, curr, next);
				swapped = true;
				prev = next;
			}
			else
				swap_pointers(&curr, &prev);
		}
	}
	return (obj_list);
}
