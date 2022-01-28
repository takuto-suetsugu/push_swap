/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:36:07 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/28 10:40:52 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	PABigThanPivot(t_node *pivot_node, t_node *guard,
		t_node *guard_dst, t_command *guard_command)
{
	t_node	*top;

	top = guard->prev;
	while (HasBigNode(guard, pivot_node) && CountNode(guard))
	{
		if (top->num > pivot_node->num)
			PA_PB(guard, guard_dst, guard_command);
		else
			RA_RB(guard, guard_command);
		top = guard->prev;
	}
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
