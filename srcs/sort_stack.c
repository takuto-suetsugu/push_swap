/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:26:03 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/14 18:41:58 by tsuetsug         ###   ########.fr       */
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
	else
		AddCommand(guard_command, "\0");
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
	t_node	*mark_node;
	t_node	*min_node;
	t_node	*median_node;

	mark_node = guard_A->prev;
	while (mark_node != guard_A->next)
	{
		if (IsMinNode(mark_node))
			min_node = mark_node;
		if (IsMedianNode(mark_node))
			median_node = mark_node;
		mark_node = mark_node->prev;
	}
}

void	SortProcess(t_node *guard_A, t_node *guard_B, t_command *guard_command)
{
	int	node_count_A;

	node_count_A = CountNode(guard_A);
	if (node_count_A <= 1)
		AddCommand(guard_command, "\0");
	else if (node_count_A == 2)
		Sort2Stack(guard_A, guard_command);
	else if (node_count_A <= 6)
		Sort6Stack(guard_A, guard_B, guard_command);
	else if (node_count_A > 6)
		SortLargeStack(guard_A, guard_B, guard_command);
}
