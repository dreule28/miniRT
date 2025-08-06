/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:42:57 by gzovkic           #+#    #+#             */
/*   Updated: 2025/05/04 11:42:58 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "garbage_collector.h"

void	clean_up(void)
{
	gc_free();
	ft_bzero(get_gc(), sizeof(t_gc_list));
}

t_gc_list	*get_gc(void)
{
	static t_gc_list	gc = {0};

	return (&gc);
}

void	gc_free(void)
{
	int			len;
	int			count;
	t_gc_list	*gc;
	t_gc_node	*tmp;
	t_gc_node	*current;

	gc = get_gc();
	if (!gc)
		return ;
	current = gc->head;
	len = gc->size;
	count = 0;
	while (current && count < len)
	{
		tmp = current->next;
		free(current->data);
		free(current);
		current = tmp;
		count++;
	}
}

void	gc_add(void *ptr)
{
	t_gc_list	*gc;
	t_gc_node	*new_node;

	if (!ptr)
		return ;
	gc = get_gc();
	if (!gc)
		return ;
	new_node = ft_calloc(1, sizeof(t_gc_node));
	if (!new_node)
		return ;
	new_node->data = ptr;
	if (gc->head == NULL)
	{
		new_node->next = NULL;
		gc->head = new_node;
		gc->tail = new_node;
	}
	else
	{
		new_node->next = gc->head;
		gc->head = new_node;
	}
	gc->size++;
}

void	gc_init(void)
{
	t_gc_list	*gc;

	gc = get_gc();
	if (!gc)
		return ;
	gc->head = NULL;
	gc->tail = NULL;
	gc->size = 0;
}
