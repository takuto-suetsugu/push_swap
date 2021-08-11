
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

void	PrintList(t_node *guard_node)
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

void	CreateStackA(int number_integers, char **integers_list)
{
	int		i;
	long	node_n;
	t_node	guard_A;

	InitGuard(&guard_A);
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
		AddNode(node_n, &guard_A);
		i++;
	}
	DeleteNode(&guard_A);
	ReverseRotateNode(&guard_A);
	PrintList(&guard_A);
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
		write(1, "1 node\n", 7);
		return (0);
	}
	write(1, "OK: ", 4);
	CreateStackA(argc, argv);
	return (0);
}
