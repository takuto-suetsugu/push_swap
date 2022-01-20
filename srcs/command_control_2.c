/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:06:57 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/20 12:07:34 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	PrintCommand(t_command *guard_command)
{
	t_command	*p;

	p = guard_command->next;
	while (p != guard_command)
	{
		write(1, p->command, ft_strlen(p->command));
		write(1, "\n", 1);
		p = p->next;
	}
}
