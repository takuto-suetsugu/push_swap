/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:03:12 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/20 17:44:12 by tsuetsug         ###   ########.fr       */
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

int	IsClassified(t_node *guard_node, t_node *pivot, t_node *head, t_node *tail)
{
	t_node	*p;

	p = guard_node->prev;
	while (p != guard_node)
	{
		if (head != guard_node && head->num <= p->num && p->num <= tail->num)
			p = p->prev;
		else if (p->num <= pivot->num)
			return (0);
		else
			p = p->prev;
	}
	return (1);
}

void	OptimizeRotate(t_node *guard_src, t_command *guard_command)
{
	t_node	*min_src;
	int		min_distance_from_top;
	
	if (IsAscending(guard_src))
			return ;
	min_src = guard_src->prev;
	min_distance_from_top = 0;
	while (!IsMinNode(min_src, guard_src))
	{
		min_src = min_src->prev;
		min_distance_from_top++;
	}
	if (CountNode(guard_src)/2 >= min_distance_from_top)
	{
		while (!IsAscending(guard_src))
			RA_RB(guard_src, guard_command);
	}
	else
	{
		while (!IsAscending(guard_src))
			RRA_RRB(guard_src, guard_command);
	}
}
