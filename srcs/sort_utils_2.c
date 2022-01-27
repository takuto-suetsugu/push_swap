/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:37:48 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/27 12:42:18 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	HasSmallNode(t_node *guard_node, t_node *pivot, t_node *head, t_node *tail)
{
	t_node	*p;

	p = guard_node->prev;
	while (p != guard_node)
	{
		if (head != guard_node && p == head)
			p = tail->prev;
		else if (p->num <= pivot->num)
			return (1);
		else
			p = p->prev;
	}
	return (0);
}

int	HasBigNode(t_node *guard_node, t_node *pivot)
{
	t_node	*p;

	p = guard_node->prev;
	while (p != guard_node)
	{
		if (p->num > pivot->num)
			return (1);
		else
			p = p->prev;
	}
	return (0);
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
	if (CountNode(guard_src) / 2 >= min_distance_from_top)
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
	t_node	*check_node;
	t_node	*p;
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
	check_node = guard_node;
	while (over_count != remain_count / 2)
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
