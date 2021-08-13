/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:26:03 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/13 11:02:40 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	CountNode(t_node *guard_node)
{
	t_node *p;
	int	count;

	p = guard_node->next;
	count = 0;
	while (p != guard_node)
	{
		p = p->next;
		count++;
	}
	return (count);
}
static void    Sort2Stack(t_node *guard_node, t_command *guard_command)
{
	t_node	*first;
	t_node	*second;

	first = guard_node->prev;
	second = first->prev;
	if (first->number > second->number)
		SA_SB(guard_node, guard_command);
	else
		AddCommand(guard_command, "\0");
}

/*
void    Sort3Stack(t_node *guard_node, t_command *guard_command)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = guard_node->prev;
	second = first->prev;
	third = second->prev;
    if (third > first > second)
        SA(guard_node, guard_command);
}
*/

void	SortProcess(t_node *guard_A, t_node *guard_B, t_command *guard_command)
{
	int	node_count_A;

	node_count_A = CountNode(guard_A);

	printf("node_count_A = %d\n", node_count_A);

	if (node_count_A <= 1)
		AddCommand(guard_command, "\0");
	else if (node_count_A == 2)
		Sort2Stack(guard_A, guard_command);
	else if (node_count_A == 3)
		Sort2Stack(guard_B, guard_command);
}