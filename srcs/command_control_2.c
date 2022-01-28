/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_control_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:06:57 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/28 18:21:40 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	PrintCommand(t_command *guard_command)
{
	t_command	*p;
	t_command	*tmp;

	p = guard_command->next;
	while (p != guard_command)
	{
		write(1, p->command, ft_strlen(p->command));
		write(1, "\n", 1);
		tmp = p;
		p = p->next;
		free(tmp);
	}
}
