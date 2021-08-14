/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:03:12 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/14 18:59:32 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	IsAscending(t_node *guard_node)
{
	t_node	*p;

	p = guard_node->prev;
	while (p->prev != guard_node)
	{
		if (p->num > (p->prev)->num)
			return (0);
		p = p->prev;
	}
	return (1);
}

int	IsDescending(t_node *guard_node)
{
	t_node	*p;

	p = guard_node->prev;
	while (p->prev != guard_node)
	{
		if (p->num < (p->prev)->num)
			return (0);
		p = p->prev;
	}
	return (1);
}

int	CountNode(t_node *guard_node)
{
	t_node	*p;
	int		count;

	p = guard_node->next;
	count = 0;
	while (p != guard_node)
	{
		p = p->next;
		count++;
	}
	return (count);
}

int IsMinNode(t_node *top, t_node *guard_node)
{
    t_node	*p;

	p = guard_node->prev;
	while (p != guard_node)
	{
		if (p->num < top->num)
			return (0);
		p = p->prev;
	}
	return (1);
}

int IsMaxNode(t_node *top, t_node *guard_node)
{
    t_node	*p;

	p = guard_node->prev;
	while (p != guard_node)
	{
		if (p->num > top->num)
			return (0);
		p = p->prev;
	}
	return (1);
}

int IsMedianNode(t_node *top, t_node *guard_node)
{
    t_node	*p;

	p = guard_node->prev;
	while (p != guard_node)
	{
		if (p->num > top->num)
			return (0);
		p = p->prev;
	}
	return (1);
}
