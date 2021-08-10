
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

void	InitGuard(t_node *guard_addr)
{
	guard_addr->number = 0;
	guard_addr->next = guard_addr;
	guard_addr->prev = guard_addr;
}

void	PrintList(t_node *guard_addr)
{
	t_node	*p;

	p = guard_addr->next;
	while (p != guard_addr)
	{
		printf("%ld, ", p->number);
		p = p->next;
	}
	printf("\n");
}

void	CreateList(int argc, char **argv)
{
	int		i;
	long	node_n;
	t_node	guard_node;

	InitGuard(&guard_node);
	i = 1;
	node_n = 0;
	while (i < argc)
	{
		node_n = ft_atoi(argv[i]);
		if (node_n > 2147483647 || node_n < -2147483648)
		{
			write(1, "Error\n", 6);
			exit (1);
		}
		AddNode(node_n, &guard_node);
		i++;
	}
	DeleteNode(&guard_node);
	PrintList(&guard_node);
}

int	main(int argc, char **argv)
{
	if (HasNonInteger(argc, argv) || HasSameNumber(argc, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc <= 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	write(1, "OK: ", 4);
	CreateList(argc, argv);
	return (0);
}
