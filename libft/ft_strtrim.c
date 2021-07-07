/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 22:14:44 by tsuetsug          #+#    #+#             */
/*   Updated: 2020/11/30 23:48:01 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_check(char word, char const *set)
{
	size_t j;

	j = 0;
	while (set[j])
	{
		if (word == set[j])
			return (1);
		j++;
	}
	return (0);
}

unsigned int	ft_len(char const *s1, char *end, char *start)
{
	unsigned int len_s1;

	len_s1 = 0;
	if (!*s1 || end == start)
		len_s1 = 1;
	else
		len_s1 = end - start + 2;
	return (len_s1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	unsigned int	len_s1;
	char			*start;
	char			*end;
	char			*trimmed_s1;

	if (!s1 && !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_check(s1[i], set))
		i++;
	start = (char *)&s1[i];
	if (ft_strlen(s1))
	{
		i = ft_strlen(s1) - 1;
		while (i >= 0 && ft_check(s1[i], set))
			i--;
	}
	end = (char *)&s1[i];
	len_s1 = ft_len(s1, end, start);
	if (!(trimmed_s1 = malloc(sizeof(char) * len_s1)))
		return (NULL);
	ft_strlcpy(trimmed_s1, start, len_s1);
	return (trimmed_s1);
}
