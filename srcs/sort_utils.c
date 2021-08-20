/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:03:12 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/20 19:26:29 by tsuetsug         ###   ########.fr       */
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

int	IsMinExcludeSorted(t_node *guard_A, t_node *guard_B,
					t_node *head, t_node *tail)
{
	t_node	*top_A;
	t_node	*p;
	
	top_A = guard_A->prev;
	p = guard_A->prev;
	if (head != guard_A && head->num <= p->num && p->num <= tail->num)
		return (0);
	while (p != guard_A)
	{
		if (head != guard_A && head->num <= p->num && p->num <= tail->num)
			p = p->prev;
		else if (p->num < top_A->num)
			return (0);
		else
			p = p->prev;
	}
	p = guard_B->prev;
	while (p != guard_B)
	{
		if (p->num < top_A->num)
			return (0);
		else
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

t_node	*SearchMedian(t_node *guard_node, t_node *head)
{
	t_node *check_node;
	t_node *p;
	int		over_count;
	int		remain_count;

	p = guard_node->prev;
	over_count = -2;
	remain_count = 0;
	while (p != head)
	{
		p = p->prev;
		remain_count++;
	}
	p = guard_node->prev;
	check_node = guard_node;
	while (over_count != remain_count/2)
	{
		check_node = check_node->prev;
		p = guard_node->prev;
		over_count = 0;
		while (p != guard_node && p != head)
		{
			if (check_node->num < p->num)
				over_count++;
			p = p->prev;
		}
	}
	return (check_node);
}