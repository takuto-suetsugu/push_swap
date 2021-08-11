/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:38:15 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/11 16:17:46 by tsuetsug         ###   ########.fr       */
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

int		main(int argc, char **argv);
int		HasNonInteger(int argc, char **argv);
int		HasSameNumber(int argc, char **argv);
void	CreateStackA(int number_integers, char **integers_list);
void	AddNode(long node_n, t_node *guard_node);
void	DeleteNode(t_node *guard_node);
void	SwapNode(t_node *guard_node);
void	RotateNode(t_node *guard_node);
void	ReverseRotateNode(t_node *guard_node);

#endif