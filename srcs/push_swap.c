/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:35:27 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/09 16:02:37 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	HasNonInteger(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	HasSameNumber(int argc, char **argv)
{
	int	i;
	int	j;
	int	cmpResult;

	i = 1;
	j = i + 1;
	cmpResult = 0;
	while (i < argc)
	{
		j = i + 1;
		while (argv[j])
		{
			cmpResult = ft_strncmp(argv[j], argv[i], ft_strlen(argv[j]));
			if (cmpResult == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
/*
int IsAscending(int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc - 1)
	{
		if (argv[i] > argv[i + 1])
			return (0);
		i++;
	}
	return (1);
}
*/

int	AddList(int argc, char **argv)
{
	struct linked_stack	*new_stack;
	int					i;
	long				stack_n;

	i = 1;
	while (i < argc)
	{
		stack_n = ft_atoi(argv[i]);
		if (stack_n > 2147483647 || stack_n < -2147483648)
			return (1);
		new_stack = malloc (sizeof(struct linked_stack));
		(*new_stack).number = stack_n;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (HasNonInteger(argc, argv) || HasSameNumber(argc, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc <= 2/*|| IsAscending(argc, argv)*/)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (AddList(argc, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	
	return (0);
}
