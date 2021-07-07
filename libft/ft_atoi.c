/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:36:23 by tsuetsug          #+#    #+#             */
/*   Updated: 2020/11/30 21:38:22 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_minus(const char *str)
{
	if (*str == '-')
		return (-1);
	else if (*str == '+')
		return (1);
	return (1);
}

int		ft_long_check(long con_str, const char *str)
{
	long ov_div;
	long ov_mod;

	ov_div = 9223372036854775807 / 10;
	ov_mod = 9223372036854775807 % 10;
	if (con_str > ov_div)
		return (-1);
	if (con_str == ov_div)
	{
		if (ov_mod < *str)
			return (-1);
	}
	return (0);
}

int		ft_atoi(const char *str)
{
	long	con_str;
	int		minus;

	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\r' || *str == '\f' || *str == '\v')
		str++;
	minus = ft_minus(str);
	if (*str == '-' || *str == '+')
		str++;
	con_str = 0;
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			break ;
		con_str = *str - 48 + con_str * 10;
		str++;
		if (ft_long_check(con_str, str) == -1)
		{
			con_str = -1;
			if (minus == -1)
				con_str = 0;
			break ;
		}
	}
	return (minus * con_str);
}
