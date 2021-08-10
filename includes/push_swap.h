/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:38:15 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/10 13:41:50 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv);
int	HasNonInteger(int argc, char **argv);
int	HasSameNumber(int argc, char **argv);
struct	t_stack *SearchTail(void);
void	AddNode(int value);

typedef struct  linked_stack
{
	long					number;
	struct linked_stack*	next;
	struct linked_stack*	prev;
}               t_stacks;

#endif