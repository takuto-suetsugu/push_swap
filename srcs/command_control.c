/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:38:02 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/11 18:01:26 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	InitCommand(t_command *guard_command)
{
	ft_memcpy(guard_command->command, "\0", sizeof(1));
	guard_command->next = guard_command;
}

void	PrintCommand(t_command *guard_command)
{
	t_command	*p;

	p = guard_command->next;
	while (p != guard_command)
	{
		printf("%s, ", p->command);
		p = p->next;
	}
	printf("\n");
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
	new_command->command = ft_memcpy(guard_command->command, *type, sizeof(type));;
	new_command->next = guard_command->next;
    guard_command->next = new_command;
}

void    SA(t_node *guard_node, t_command *guard_command)
{
    SwapNode(guard_node);
    if (guard_node->number == 1)
        AddCommand(guard_command, 'sa');
    if (guard_node->number == 2)
        AddCommand(guard_command, 'sb');
}