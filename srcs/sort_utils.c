/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:03:12 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/14 12:34:34 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	IsAscending(t_node *guard_node)
{
	t_node	*p;

	p = guard_node->prev;
	while (p->prev != guard_node)
	{
		if (p->num > (p->prev)->num)
			return (0);
		p = p->prev;
	}
	return (1);
}

int	IsDescending(t_node *guard_node)
{
	t_node	*p;

	p = guard_node->prev;
	while (p->prev != guard_node)
	{
		if (p->num < (p->prev)->num)
			return (0);
		p = p->prev;
	}
	return (1);
}

int	CountNode(t_node *guard_node)
{
	t_node	*p;
	int		count;

	p = guard_node->next;
	count = 0;
	while (p != guard_node)
	{
		p = p->next;
		count++;
	}
	return (count);
}

int IsMinNode(t_node *top, t_node *guard_node)
{
    t_node	*p;

	p = guard_node->prev;
	while (p != guard_node)
	{
		if (p->num < top->num)
			return (0);
		p = p->prev;
	}
	return (1);
}

int IsMaxNode(t_node *top, t_node *guard_node)
{
    t_node	*p;

	p = guard_node->prev;
	while (p != guard_node)
	{
		if (p->num > top->num)
			return (0);
		p = p->prev;
	}
	return (1);
}

void	InsertNode(t_node *guard_src, t_node *guard_dst, t_command *guard_command)
{
	t_node	*A_top;
	t_node	*A_bottom;
	t_node	*B_top;

	A_top = guard_dst->prev;
	A_bottom = guard_dst->next;
	B_top = guard_src->prev;
	if (IsMinNode(B_top, guard_dst) || IsMaxNode(B_top, guard_dst))
	{
		while (!(IsAscending(guard_dst)))
			RA_RB(guard_dst, guard_command);
	}
	else{
		while (!(A_bottom->num < B_top->num && B_top->num < A_top->num))
		{
			RA_RB(guard_dst, guard_command);
			A_top = guard_dst->prev;
			A_bottom = guard_dst->next;
			B_top = guard_src->prev;
		}
	}
	PA_PB(guard_src, guard_dst, guard_command);
}
