/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_control_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:06:57 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/28 17:01:28 by tsuetsug         ###   ########.fr       */
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
		free(p);
		p = p->next;
	}
}
