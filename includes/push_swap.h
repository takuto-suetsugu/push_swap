/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:38:15 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/20 19:05:39 by tsuetsug         ###   ########.fr       */
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
	long			num;
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

void	CreateNode(long node_n, t_node *guard_node);
void	AddNode(t_node *add_node, t_node *guard_node);
void	DeleteNode(t_node *guard_node);
void	SwapNode(t_node *guard_node);
void	RotateNode(t_node *guard_node);
void	ReverseRotateNode(t_node *guard_node);

void	PrintCommand(t_command *guard_command);
void    AddCommand(t_command *guard_command, char *type);
void    SA_SB(t_node *guard_node, t_command *guard_command);
void	RA_RB(t_node *guard_node, t_command *guard_command);
void	RRA_RRB(t_node *guard_node, t_command *guard_command);
void	PA_PB(t_node *guard_src, t_node *guard_dst, t_command *guard_command);

int		IsAscending(t_node *guard_node);
int		IsDescending(t_node *guard_node);
int		CountNode(t_node *guard_node);
int 	IsMaxNode(t_node *top, t_node *guard_node);
int 	IsMinNode(t_node *top, t_node *guard_node);
int	IsMinExcludeSorted(t_node *guard_A, t_node *guard_B,
					t_node *head, t_node *tail);
int		IsClassified(t_node *guard_node, t_node *pivot, t_node *head, t_node *tail);
void	InsertNode(t_node *guard_src, t_node *guard_dst, t_command *guard_command);
void	OptimizeRotate(t_node *guard_src, t_command *guard_command);
t_node	*SearchMedian(t_node *guard_node, t_node *head);

void	PrintNumber(t_node *guard);

#endif