/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 22:10:08 by tsuetsug          #+#    #+#             */
/*   Updated: 2020/11/30 22:10:29 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int word, size_t len)
{
	unsigned char *str;

	str = (unsigned char *)dst;
	while (len > 0)
	{
		*str = word;
		str++;
		len--;
	}
	return (dst);
}
