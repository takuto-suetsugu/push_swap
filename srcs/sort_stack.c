/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:26:03 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/28 10:38:42 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


t_node	*MoveAtoBProc(t_node *guard_A, t_node *guard_B, t_node *pivot_node,
		t_node *sorted_head, t_command *guard_command)
{
	t_node	*sorted_tail;

	sorted_tail = guard_A;
	sorted_head = RAIfMin(guard_A, sorted_head, guard_command);
	if (sorted_head != guard_A)
		sorted_tail = guard_A->next;
	while (HasSmallNode(guard_A, pivot_node, sorted_head, sorted_tail))
		PBSmallThanPivot(pivot_node, guard_A, guard_B, guard_command);
	OptimizeRotateTailBottom(sorted_tail, guard_A, guard_command);
	return (sorted_head);
}


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

	if (CountNode(guard_src) == 2)
		Sort2Stack(guard_src, guard_command);
	if (IsAscending(guard_src))
		return ;
	dst_top = guard_dst->prev;
	while (CountNode(guard_src) > 3)
		PA_PB(guard_src, guard_dst, guard_command);
	Sort3Stack(guard_src, guard_command);
	while (guard_dst->prev != dst_top)
		InsertNode(guard_dst, guard_src, guard_command);
	OptimizeRotateMinTop(guard_src, guard_command);
}

static void	SortLargeStack(t_node *guard_A, t_node *guard_B, t_command *guard_command)
{
	t_node	*sorted_head;
	t_node	*sorted_tail;
	t_node	*pivot_node;

	sorted_head = guard_A;
	sorted_tail = guard_A;
	pivot_node = SearchMedian(guard_A, sorted_head);
	while (!(IsAscending(guard_A)))
	{
		sorted_head = RAIfMin(guard_A, sorted_head, guard_command);
		if (sorted_head != guard_A)
			sorted_tail = guard_A->next;
		while (HasSmallNode(guard_A, pivot_node, sorted_head, sorted_tail))
			PBSmallThanPivot(pivot_node, guard_A, guard_B, guard_command);
		OptimizeRotateTailBottom(sorted_tail, guard_A, guard_command);
		while (CountNode(guard_B) >= 7)
		{
			sorted_head = RBIfMin(guard_B, guard_A, sorted_head, guard_command);
			pivot_node = SearchMedian(guard_B, guard_B);
			PABigThanPivot(pivot_node, guard_B, guard_A, guard_command);
		}
		Sort6Stack(guard_B, guard_A, guard_command);
		sorted_head = PASorted(sorted_head, guard_A, guard_B, guard_command);
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
