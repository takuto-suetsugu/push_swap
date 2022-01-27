/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:44:32 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/27 15:44:50 by tsuetsug         ###   ########.fr       */
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
