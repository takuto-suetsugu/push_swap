/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:38:02 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/12 11:41:07 by tsuetsug         ###   ########.fr       */
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

void    AddCommand(t_command *guard_command, char *type)
{
	t_command	*new_command;

	new_command = malloc (sizeof(t_command));
	if (new_command == NULL)
	{
		write(1, "Error\n", 6);
		exit (4);
	}
	ft_memcpy(guard_command->command, type, sizeof(type));
	new_command->next = guard_command->next;
    guard_command->next = new_command;
}

void    SA_SB(t_node *guard_node, t_command *guard_command)
{
    SwapNode(guard_node);
    if (guard_node->number == 1)
        AddCommand(guard_command, "sa");
    if (guard_node->number == 2)
        AddCommand(guard_command, "sb");
}