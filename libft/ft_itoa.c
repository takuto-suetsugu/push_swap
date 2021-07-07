/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:39:33 by tsuetsug          #+#    #+#             */
/*   Updated: 2020/11/30 21:41:29 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_itoa_len(int n)
{
	size_t		r;

	if (n == 0)
		return (1);
	r = 0;
	if (n < 0)
		r++;
	while (n)
	{
		n /= 10;
		r++;
	}
	return (r);
}

char	*ft_itoa(int n)
{
	size_t		len_n;
	size_t		minus;
	char		*char_n;

	len_n = ft_itoa_len(n);
	if (!(char_n = (char *)malloc(len_n + 1)))
		return (NULL);
	if (n >= 0)
		minus = 0;
	if (n < 0)
	{
		char_n[0] = '-';
		minus = 1;
	}
	char_n[len_n] = '\0';
	while (len_n-- > minus)
	{
		if (n >= 0)
			char_n[len_n] = '0' + n % 10 * 1;
		else if (n < 0)
			char_n[len_n] = '0' + n % 10 * -1;
		n /= 10;
	}
	return (char_n);
}
