/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 22:11:52 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/28 11:16:50 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*connected_s;
	int		i;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!(connected_s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2))
		+ 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		connected_s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		connected_s[i] = s2[j];
		i++;
		j++;
	}
	connected_s[i] = '\0';
	return (connected_s);
}
