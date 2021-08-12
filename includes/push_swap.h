/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:38:15 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/12 11:47:23 by tsuetsug         ###   ########.fr       */
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

typedef	struct s_command
{
	char				command[4];
	struct s_command*	next;
}				t_command;

int		main(int argc, char **argv);
int		HasNonInteger(int argc, char **argv);
int		HasSameNumber(int argc, char **argv);

void	SortProcess(t_node *guard_A, t_node *guard_B, t_command *guard_command);
void	AddNode(long node_n, t_node *guard_node);
void	DeleteNode(t_node *guard_node);
void	SwapNode(t_node *guard_node);
void	RotateNode(t_node *guard_node);
void	ReverseRotateNode(t_node *guard_node);

void	PrintCommand(t_command *guard_command);
void    AddCommand(t_command *guard_command, char *type);
void    SA_SB(t_node *guard_node, t_command *guard_command);

void    Sort3Stack(t_node *guard_node, t_command *guard_command);

#endif