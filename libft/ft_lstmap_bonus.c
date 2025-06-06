/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:52:55 by dreule            #+#    #+#             */
/*   Updated: 2024/10/18 12:39:59 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_nodes(t_list **list, void (*del)(void *))
{
	t_list	*node;

	while (*list != NULL)
	{
		node = *list;
		*list = (*list)->next;
		del(node->content);
		free(node);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	t_list	*last_node;

	new_lst = NULL;
	last_node = NULL;
	while (lst != NULL)
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
		{
			free_nodes(&new_lst, del);
			del(f(lst->content));
			return (NULL);
		}
		new_node->content = f(lst->content);
		new_node->next = NULL;
		if (!new_lst)
			new_lst = new_node;
		else
			last_node->next = new_node;
		last_node = new_node;
		lst = lst->next;
	}
	return (new_lst);
}
