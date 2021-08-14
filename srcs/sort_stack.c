/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:26:03 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/14 16:15:31 by tsuetsug         ###   ########.fr       */
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

static void	Sort3Node(t_node *guard_node, t_command *guard_command)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

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

static void	Sort3Stack(t_node *guard_node, t_command *guard_command)
{
	while (!IsAscending(guard_node))
		Sort3Node(guard_node, guard_command);
}

static void	Sort5Stack(t_node *guard_A, t_node *guard_B,
						t_command *guard_command)
{
	if (IsAscending(guard_A))
		return ;
	while (CountNode(guard_A) > 3)
		PA_PB(guard_A, guard_B, guard_command);
	if	(!(IsAscending(guard_A)))
		Sort3Node(guard_A, guard_command);
	while (CountNode(guard_B))
		InsertNode(guard_B, guard_A, guard_command);
	while (!(IsAscending(guard_A)))
		RA_RB(guard_A, guard_command);
}


void	SortProcess(t_node *guard_A, t_node *guard_B, t_command *guard_command)
{
	int	node_count_A;

	node_count_A = CountNode(guard_A);
	if (node_count_A <= 1)
		AddCommand(guard_command, "\0");
	else if (node_count_A == 2)
		Sort2Stack(guard_A, guard_command);
	else if (node_count_A == 3)
		Sort3Stack(guard_A, guard_command);
	else if (node_count_A <= 15)
		Sort5Stack(guard_A, guard_B, guard_command);
	else if (node_count_A > 5)
		SortLargeStack(guard_A, guard_B, guard_command);
}
