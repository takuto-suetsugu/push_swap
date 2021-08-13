/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:41:11 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/11 17:53:27 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	AddNode(long node_n, t_node *guard_node)
{
	t_node	*first_node;
	t_node	*new_node;

	first_node = guard_node->prev;
	new_node = malloc (sizeof(t_node));
	if (new_node == NULL)
	{
		write(1, "Error\n", 6);
		exit (2);
	}
	new_node->number = node_n;
	new_node->next = guard_node;
	new_node->prev = first_node;
	first_node->next = new_node;
	guard_node->prev = new_node;
}

void	DeleteNode(t_node *guard_node)
{
	t_node	*first_node;
	t_node	*second_node;

	first_node = guard_node->prev;
	second_node = first_node->prev;
	second_node->next = guard_node;
	guard_node->prev = second_node;
	free (first_node);
}

void	SwapNode(t_node *guard_node)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*third_node;

	first_node = guard_node->prev;
	second_node = first_node->prev;
	third_node = second_node->prev;
	first_node->next = second_node;
	second_node->prev = first_node;
	second_node->next = guard_node;
	guard_node->prev = second_node;
	third_node->next = first_node;
	first_node->prev = third_node;
}

void	RotateNode(t_node *guard_node)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*last_node;

	first_node = guard_node->prev;
	second_node = first_node->prev;
	last_node = guard_node->next;
	first_node->next = last_node;
	last_node->prev = first_node;
	second_node->next = guard_node;
	guard_node->prev = second_node;
	guard_node->next = first_node;
	first_node->prev = guard_node;
}

void	ReverseRotateNode(t_node *guard_node)
{
	t_node	*first_node;
	t_node	*last_node;
	t_node	*second_last_node;

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