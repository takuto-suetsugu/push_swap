/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_control_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:12:42 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/28 19:11:10 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ReverseRotateNode(t_node *guard_node)
{
	t_node	*first_node;
	t_node	*last_node;
	t_node	*second_last_node;

	if (CountNode(guard_node) <= 1)
		return ;
	first_node = guard_node->prev;
	last_node = guard_node->next;
	second_last_node = last_node->next;
	first_node->next = last_node;
	last_node->prev = first_node;
	last_node->next = guard_node;
	guard_node->prev = last_node;
	guard_node->next = second_last_node;
	second_last_node->prev = guard_node;
}

void	InsertNode(t_node *guard_src, t_node *guard_dst, t_command *guard_cmd)
{
	t_node	*src_A;
	t_node	*src_bottom;
	t_node	*dst_top;

	src_A = guard_dst->prev;
	src_bottom = guard_dst->next;
	dst_top = guard_src->prev;
	if (IsMinNode(dst_top, guard_dst) || IsMaxNode(dst_top, guard_dst))
	{
		while (!(IsAscending(guard_dst)))
			RA_RB(guard_dst, guard_cmd);
	}
	else
	{
		while (!(src_bottom->num < dst_top->num && dst_top->num < src_A->num))
		{
			RA_RB(guard_dst, guard_cmd);
			src_A = guard_dst->prev;
			src_bottom = guard_dst->next;
			dst_top = guard_src->prev;
		}
	}
	PA_PB(guard_src, guard_dst, guard_cmd);
}

void	FreeNode(t_node *guard_node)
{
	t_node	*p;

	p = guard_node->prev;
	while (p != guard_node)
	{
		p = p->prev;
		free(p->next);
	}
}
