/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:41:11 by tsuetsug          #+#    #+#             */
/*   Updated: 2021/08/10 13:41:19 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

struct	t_stack *SearchTail(void)
{
	struct	t_stack	*p = &list;

	while (p->next != &GuardNode)
		p = p->next;
	
	return p;
}

void	AddNode(int value)
{
	struct t_stack	*tail;
	struct t_stack	*new_stack;

	tail = SearchTail();
	new_stack = malloc (sizeof(struct linked_stack));
	if (new_stack == NULL)
		return (1);
	new_stack->number = value;
	new_stack->next = NULL;
	new_stack->prev = tail;
	tail->next = new_stack;
}