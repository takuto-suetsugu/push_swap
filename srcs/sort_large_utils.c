/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:36:07 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/27 15:36:36 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*PASorted(t_node *sorted_head, t_node *guard_A, t_node *guard_B,
		t_command *guard_command)
{
	if (sorted_head == guard_A)
		sorted_head = guard_B->prev;
	while (CountNode(guard_B))
	{
		PA_PB(guard_B, guard_A, guard_command);
		RA_RB(guard_A, guard_command);
	}
	return (sorted_head);
}

void	OptimizeRotateTailBottom(t_node *tail, t_node *guard,
		t_command *guard_command)
{
	int		tail_distance_from_top;
	t_node	*tmp;

	if (tail == guard || tail == guard->next)
		return ;
	tmp = tail;
	tail_distance_from_top = 0;
	while (tmp != guard)
	{
		tmp = tmp->next;
		tail_distance_from_top++;
	}
	if (tail_distance_from_top <= CountNode(guard) / 2)
	{
		while (tail != guard->next)
			RA_RB(guard, guard_command);
	}
	else
	{
		while (tail != guard->next)
			RRA_RRB(guard, guard_command);
	}
}

void	PABigThanPivot(t_node *pivot_node, t_node *guard,
		t_node *guard_dst, t_command *guard_command)
{
	t_node	*top;

	top = guard->prev;
	if (top->num > pivot_node->num)
		PA_PB(guard, guard_dst, guard_command);
	else
		RA_RB(guard, guard_command);
	top = guard->prev;
}

void	PBSmallThanPivot(t_node *pivot_node, t_node *guard,
		t_node *guard_dst, t_command *guard_command)
{
	t_node	*top;

	top = guard->prev;
	if (top->num <= pivot_node->num)
		PA_PB(guard, guard_dst, guard_command);
	else
		RA_RB(guard, guard_command);
	top = guard->prev;
}

t_node	*RBIfMin(t_node *guard, t_node *guard_dst,
		t_node *sorted_head, t_command *guard_command)
{
	t_node	*top;

	top = guard->prev;
	while ((IsMinNode(top, guard) || IsMinNode(top->prev, guard))
		&& CountNode(guard))
	{
		if (!IsMinNode(top, guard) && IsMinNode(top->prev, guard))
			SA_SB(guard, guard_command);
		PA_PB(guard, guard_dst, guard_command);
		RA_RB(guard_dst, guard_command);
		if (sorted_head == guard_dst)
			sorted_head = guard_dst->next;
		top = guard->prev;
	}
	return (sorted_head);
}

t_node	*RAIfMin(t_node *guard, t_node *sorted_head,
		t_command *guard_command)
{
	t_node	*top;

	top = guard->prev;
	while (IsMinExcludeSorted(top, guard, sorted_head)
			|| IsMinExcludeSorted(top->prev, guard, sorted_head))
	{
		if (IsMinExcludeSorted(top->prev, guard, sorted_head))
			SA_SB(guard, guard_command);
		RA_RB(guard, guard_command);
		if (sorted_head == guard)
			sorted_head = guard->next;
		top = guard->prev;
	}
	return (sorted_head);
}
