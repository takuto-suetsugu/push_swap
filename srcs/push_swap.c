/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:35:27 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/20 12:17:19 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	InitGuard(t_node *guard_node, long num)
{
	guard_node->num = num;
	guard_node->next = guard_node;
	guard_node->prev = guard_node;
}

void	InitCommand(t_command *guard_command)
{
	ft_bzero(guard_command->command, sizeof(guard_command->command));
	guard_command->next = guard_command;
}

static void	CreateStackA(int argc, char **argv, t_node *guard_A)
{
	int		i;
	long	node_n;

	i = argc - 1;
	node_n = 0;
	while (i > 0)
	{
		node_n = ft_atoi(argv[i]);
		if (node_n < -2147483648 || 2147483647 < node_n)
		{
			write(1, "Error\n", 6);
			exit (1);
		}
		CreateNode(node_n, guard_A);
		i--;
	}
}

int	main(int argc, char **argv)
{
	t_node		guard_A;
	t_node		guard_B;
	t_command	guard_command;

	InitGuard(&guard_A, 1);
	InitGuard(&guard_B, 2);
	InitCommand(&guard_command);
	if (HasNonInteger(argc, argv) || HasSameNumber(argc, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	CreateStackA(argc, argv, &guard_A);
	SortProcess(&guard_A, &guard_B, &guard_command);
	PrintCommand(&guard_command);
	return (0);
}
