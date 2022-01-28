/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:33:25 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/28 11:25:06 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;
	unsigned int	i;

	if (n == 0)
		return (0);
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	i = 0;
	while ((i < n - 1) && ptr_s1[i] && ptr_s2[i] && (ptr_s1[i] == ptr_s2[i]))
		i++;
	return ((unsigned char)ptr_s1[i] - (unsigned char)ptr_s2[i]);
}
