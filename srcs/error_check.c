/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:38:02 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/28 16:44:52 by tsuetsug         ###   ########.fr       */
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
		if (argv[i][0] == '-' && argv[i][1] != '\0')
			j++;
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
			if (ft_strlen(argv[i]) >= ft_strlen(argv[j]))
				cmpResult = ft_strncmp(argv[i], argv[j], ft_strlen((argv[i])));
			else
				cmpResult = ft_strncmp(argv[i], argv[j], ft_strlen((argv[j])));
			if (cmpResult == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
