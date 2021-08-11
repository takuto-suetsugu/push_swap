
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:35:27 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/10 16:37:44 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	InitGuard(t_node *guard_node)
{
	guard_node->number = 0;
	guard_node->next = guard_node;
	guard_node->prev = guard_node;
}

void	InitCommand(t_command *guard_command)
{
	ft_memcpy(guard_command->command, "\0", sizeof(1));
	guard_command->next = guard_command;
}

void	PrintNumber(t_node *guard_node)
{
	t_node	*p;

	p = guard_node->next;
	while (p != guard_node)
	{
		printf("%ld, ", p->number);
		p = p->next;
	}
	printf("\n");
}

void	PrintList(t_command *guard_command)
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

void	CreateStackA(int number_integers, char **integers_list, t_node *guard_A)
{
	int		i;
	long	node_n;

	i = 1;
	node_n = 0;
	while (i < number_integers)
	{
		node_n = ft_atoi(integers_list[i]);
		if (node_n < -2147483648 || 2147483647 < node_n)
		{
			write(1, "Error\n", 6);
			exit (1);
		}
		AddNode(node_n, guard_A);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_node		guard_A;
	t_node		guard_B;
	t_command	guard_command;

	InitGuard(&guard_A);
	guard_A.number = 1;
	InitGuard(&guard_B);
	guard_B.number = 2;
	InitCommand(&guard_command);
	if (HasNonInteger(argc, argv) || HasSameNumber(argc, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc <= 2)
	{
		write(1, "1 node\n", 7);
		return (0);
	}
	write(1, "OK: ", 4);
	CreateStackA(argc, argv, &guard_A);
	PrintNumber(&guard_A);

	if (argv == 3)
		Sort3Stack(&guard_A, guard_command);
	PrintList(&guard_command);
	return (0);
}
