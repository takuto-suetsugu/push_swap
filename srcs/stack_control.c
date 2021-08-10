/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:41:11 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/10 19:03:59 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*SearchTail(t_node *guard_addr)
{
	t_node  *p;
	
	p = guard_addr;
	while (p->next != guard_addr)
		p = p->next;
	return (p);
}

void	AddNode(long node_n, t_node *guard_addr)
{
	t_node	*tail;
	t_node	*new_node;

	tail = SearchTail(guard_addr);
	new_node = malloc (sizeof(t_node));
	if (new_node == NULL)
	{
		write(1, "Error\n", 6);
		exit (2);
	}
	new_node->number = node_n;
	new_node->next = guard_addr;
	new_node->prev = tail;
	tail->next = new_node;
	guard_addr->prev = new_node;
}

void	DeleteNode(t_node *guard_addr)
{
	t_node	*tail;
	t_node	*prev_node;

	tail = SearchTail(guard_addr);
	prev_node = tail->prev;
	prev_node->next = guard_addr;
	guard_addr->prev = prev_node;
	free (tail);	
}