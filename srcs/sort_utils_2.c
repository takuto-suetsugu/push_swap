/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:37:48 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/28 10:53:16 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	HasSmallNode(t_node *guard_node, t_node *pivot,
					t_node *sorted_head, t_node *tail)
{
	t_node	*p;

	p = guard_node->prev;
	while (p != guard_node)
	{
		if (sorted_head != guard_node && p == sorted_head)
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

void	OptimizeRotateMinTop(t_node *guard_src, t_command *guard_command)
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

t_node	*SearchMedian(t_node *guard_node)
{
	t_node	*check_node;
	t_node	*p;
	int		above_average_count;
	int		node_count;

	p = guard_node->prev;
	above_average_count = 0;
	node_count = CountNode(guard_node);
	check_node = guard_node;
	while (above_average_count != node_count / 2)
	{
		check_node = check_node->prev;
		p = guard_node->prev;
		above_average_count = 0;
		while (p != guard_node && p != guard_node)
		{
			if (check_node->num < p->num)
				above_average_count++;
			p = p->prev;
		}
	}
	return (check_node);
}
