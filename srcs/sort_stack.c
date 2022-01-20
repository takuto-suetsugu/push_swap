/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:26:03 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/20 13:06:30 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	Sort2Stack(t_node *guard_node, t_command *guard_command)
{
	t_node	*first;
	t_node	*second;

	first = guard_node->prev;
	second = first->prev;
	if (first->num > second->num)
		SA_SB(guard_node, guard_command);
}

static void	Sort3Stack(t_node *guard_node, t_command *guard_command)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (IsAscending(guard_node))
		return ;
	first = guard_node->prev;
	second = first->prev;
	third = second->prev;
	if (second->num < third->num && third->num < first->num)
		RA_RB(guard_node, guard_command);
	else if (third->num < first->num && first->num < second->num)
		RRA_RRB(guard_node, guard_command);
	else
		SA_SB(guard_node, guard_command);
}

static void	Sort6Stack(t_node *guard_src, t_node *guard_dst,
						t_command *guard_command)
{
	t_node	*dst_top;

	if (IsAscending(guard_src))
		return ;
	dst_top = guard_dst->prev;
	while (CountNode(guard_src) > 3)
		PA_PB(guard_src, guard_dst, guard_command);
	Sort3Stack(guard_src, guard_command);
	while (guard_dst->prev != dst_top)
		InsertNode(guard_dst, guard_src, guard_command);
	OptimizeRotate(guard_src, guard_command);
}

static void	SortLargeStack(t_node *guard_A, t_node *guard_B,
							t_command *guard_command)
{
	t_node	*pivot_node;
	t_node	*top_A;
	t_node	*top_B;
	t_node	*sorted_head;
	t_node	*sorted_tail;

	sorted_head = guard_A;
	sorted_tail = guard_A;
	top_A = guard_A->prev;
	top_B = guard_B->prev;
	pivot_node = SearchMedian(guard_A, sorted_head);
	while (!(IsAscending(guard_A)))
	{
		top_A = guard_A->prev;
		while (IsMinExcludeSorted(top_A, guard_A, sorted_head)
			|| IsMinExcludeSorted(top_A->prev, guard_A, sorted_head))
		{
			if (IsMinExcludeSorted(top_A->prev, guard_A, sorted_head))
				SA_SB(guard_A, guard_command);
			RA_RB(guard_A, guard_command);
			if (sorted_head == guard_A)
				sorted_head = guard_A->next;
			sorted_tail = guard_A->next;
			top_A = guard_A->prev;
		}
		while (HasSmallNode(guard_A, pivot_node, sorted_head, sorted_tail))
		{
			if (top_A->num <= pivot_node->num)
				PA_PB(guard_A, guard_B, guard_command);
			else
				RA_RB(guard_A, guard_command);
			top_A = guard_A->prev;
		}
		while (sorted_tail != guard_A && sorted_tail != guard_A->next)
			RRA_RRB(guard_A, guard_command);
		while (CountNode(guard_B) > 5)
		{
			top_B = guard_B->prev;
			while ((IsMinNode(top_B, guard_B)
					|| (IsMinNode(top_B->prev, guard_B))) && CountNode(guard_B))
			{
				if (!IsMinNode(top_B, guard_B)
					&& IsMinNode(top_B->prev, guard_B))
					SA_SB(guard_B, guard_command);
				PA_PB(guard_B, guard_A, guard_command);
				RA_RB(guard_A, guard_command);
				if (sorted_head == guard_A)
					sorted_head = guard_A->next;
				sorted_tail = guard_A->next;
				top_B = guard_B->prev;
			}
			pivot_node = SearchMedian(guard_B, guard_B);
			while (HasBigNode(guard_B, pivot_node) && CountNode(guard_B))
			{
				if (top_B->num > pivot_node->num)
					PA_PB(guard_B, guard_A, guard_command);
				else
					RA_RB(guard_B, guard_command);
				top_B = guard_B->prev;
			}
		}
		if (CountNode(guard_B) == 2)
			Sort2Stack(guard_B, guard_command);
		else if (CountNode(guard_B) >= 3)
			Sort6Stack(guard_B, guard_A, guard_command);
		if (sorted_head == guard_A)
			sorted_head = guard_B->prev;
		while (CountNode(guard_B))
		{
			PA_PB(guard_B, guard_A, guard_command);
			RA_RB(guard_A, guard_command);
		}
		sorted_tail = guard_A->next;
		pivot_node = guard_A->prev;
	}
}

void	SortProcess(t_node *guard_A, t_node *guard_B, t_command *guard_command)
{
	int	node_count_A;

	node_count_A = CountNode(guard_A);
	if (node_count_A <= 1 || IsAscending(guard_A))
		AddCommand(guard_command, "\0");
	else if (node_count_A == 2)
		Sort2Stack(guard_A, guard_command);
	else if (node_count_A <= 6)
		Sort6Stack(guard_A, guard_B, guard_command);
	else if (node_count_A > 6)
		SortLargeStack(guard_A, guard_B, guard_command);
}
