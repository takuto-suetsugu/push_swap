/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:38:02 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/13 14:57:21 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	PrintCommand(t_command *guard_command)
{
	t_command	*p;

	p = guard_command->next;
	while (p != guard_command)
	{
		write(1, p->command, ft_strlen(p->command));
		write(1, "\n", 1);
		p = p->next;
	}
}

void	AddCommand(t_command *guard_command, char *type)
{
	t_command	*new_command;
	t_command	*tail;

	new_command = malloc (sizeof(t_command));
	if (new_command == NULL)
	{
		write(1, "Error\n", 6);
		exit (4);
	}
	tail = guard_command->next;
	while (tail->next != guard_command)
		tail = tail->next;
	ft_memcpy(new_command->command, type, sizeof(type));
	new_command->next = guard_command;
	tail->next = new_command;
}

void	SA_SB(t_node *guard_node, t_command *guard_command)
{
	SwapNode(guard_node);
	if (guard_node->num == 1)
		AddCommand(guard_command, "sa");
	if (guard_node->num == 2)
		AddCommand(guard_command, "sb");
}

void	RA_RB(t_node *guard_node, t_command *guard_command)
{
	RotateNode(guard_node);
	if (guard_node->num == 1)
		AddCommand(guard_command, "ra");
	if (guard_node->num == 2)
		AddCommand(guard_command, "rb");
}

void	RRA_RRB(t_node *guard_node, t_command *guard_command)
{
	ReverseRotateNode(guard_node);
	if (guard_node->num == 1)
		AddCommand(guard_command, "rra");
	if (guard_node->num == 2)
		AddCommand(guard_command, "rrb");
}

void	PA_PB(t_node *guard_src, t_node *guard_dst, t_command *guard_command)
{
	t_node	*first_src;
	
	first_src = guard_src->prev;
	AddNode(first_src->num, guard_dst);
	DeleteNode(guard_src);
	if (guard_src->num == 1)
		AddCommand(guard_command, "pa");
	if (guard_src->num == 2)
		AddCommand(guard_command, "pb");
}
