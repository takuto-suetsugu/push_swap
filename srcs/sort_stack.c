/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:26:03 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/15 23:50:09 by tsuetsug         ###   ########.fr       */
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

static void	Sort6Stack(t_node *guard_A, t_node *guard_B,
						t_command *guard_command)
{
	if (IsAscending(guard_A))
		return ;
	while (CountNode(guard_A) > 3)
		PA_PB(guard_A, guard_B, guard_command);
	Sort3Stack(guard_A, guard_command);
	while (CountNode(guard_B))
		InsertNode(guard_B, guard_A, guard_command);
	while (!(IsAscending(guard_A)))
		RA_RB(guard_A, guard_command);
}

static void	SortLargeStack(t_node *guard_A, t_node *guard_B,
							t_command *guard_command)
{
	t_node	*pivot_node;
	t_node	*top_A;
	t_node	*top_B;

	pivot_node = guard_A->prev;
	while (!(IsAscending(guard_A)))
	{
		pivot_node = guard_A->prev;
		if (IsMinNode(pivot_node, guard_A) == 1)
			RA_RB(guard_A, guard_command);
		top_A = guard_A->prev;
		while (top_A != guard_A && !(IsAscending(guard_A)))
		{
			if (top_A->num <= pivot_node->num)
				PA_PB(guard_A, guard_B, guard_command);
			else
				RA_RB(guard_A, guard_command);
			top_A = top_A->prev;
		}
		while (CountNode(guard_B) > 6)
		{
			pivot_node = guard_B->prev;
			if (IsMinNode(pivot_node, guard_B) == 1)
			{
				PA_PB(guard_B, guard_A, guard_command);
				RA_RB(guard_A, guard_command);
			}
			top_B = guard_B->prev;
			while (top_B != guard_A)
			{
				if (top_B->num > pivot_node->num)
					PA_PB(guard_B, guard_A, guard_command);
				else
					RA_RB(guard_B, guard_command);
				top_B = top_B->prev;
			}
		}
		if (CountNode(guard_B) == 2)
			Sort2Stack(guard_B, guard_command);
		else if (CountNode(guard_B) >= 3)
			Sort6Stack(guard_B, guard_A, guard_command);
		while (CountNode(guard_B) > 0)
		{
			PA_PB(guard_B, guard_A, guard_command);
			RA_RB(guard_A, guard_command);
		}
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
