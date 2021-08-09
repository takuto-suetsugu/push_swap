/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:35:27 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/09 15:44:47 by tsuetsug         ###   ########.fr       */
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

int	*AllAtoi(int argc, char **argv)
{
	int	*numbers;
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (0);
		numbers[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (numbers);
}

int	AddList(int argc, char **argv)
{
	struct linked_stack	*new_stack;
	int					i;

	i = 1;
	if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
		return (1);
	new_stack = malloc (sizeof(char) * linked_stack);
	ft_strlcpy((*new_stack).number, number, sizeof(number));
	return (0);
}

int	main(int argc, char **argv)
{
	stack_numbers = AllAtoi(argc, argv);
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
	write(1, "OK\n", 3);
	if (AddList(argc, argv) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (0);
}
