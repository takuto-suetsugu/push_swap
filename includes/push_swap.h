/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:38:15 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/10 19:05:33 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct  s_node
{
	long			number;
	struct s_node*	next;
	struct s_node*	prev;
}               t_node;

int 	main(int argc, char **argv);
int		HasNonInteger(int argc, char **argv);
int		HasSameNumber(int argc, char **argv);
void	AddNode(long node_n, t_node *guard_addr);
void	DeleteNode(t_node *guard_addr);
t_node	*SearchTail(t_node *guard_addr);

#endif