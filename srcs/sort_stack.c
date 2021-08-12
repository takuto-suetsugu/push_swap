/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:26:03 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/12 11:24:05 by tsuetsug         ###   ########.fr       */
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
	if (node_count_A <= 1)
		write(1, "\n", 1);
	else if (node_count_A == 2)
		Sort2Stack(&guard_A, &guard_command);
}