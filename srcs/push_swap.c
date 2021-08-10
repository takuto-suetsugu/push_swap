/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:35:27 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/10 13:46:31 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
int	CreateList(int argc, char **argv)
{
	int					i;
	long				stack_n;

	t_stack.next = &t_stack;
	t_stack.prev = &t_stack;
	i = 1;
	while (i < argc)
	{
		stack_n = ft_atoi(argv[i]);
		if (stack_n > 2147483647 || stack_n < -2147483648)
			return (1);
		AddNode(stack_n);
	}
	return (0);
}

void	InitGuard(struct t_stack)
{
	GuardNode.number = 0;
	GuardNode.next = NULL;
	GuardNode.prev = NULL;
}
*/


int	main(int argc, char **argv)
{
	//struct t_stack GuardNode;
	
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
	write(1, "OK\n", 4);
	/*
	InitGuard(t_stack);
	if (CreateList(argc, argv, linked_stack))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	*/	
	return (0);
}
