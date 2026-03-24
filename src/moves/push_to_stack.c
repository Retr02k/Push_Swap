/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:06:27 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/24 13:11:53 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static t_node	*pop_top_node(t_stack *src)
{
	t_node	*node;

	if (src->head == NULL)
		return (NULL);
	node = src->head;
	if (node->next == node)
		src->head = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		src->head = node->next;
	}
	src->size--;
	return (node);
}

static void	push_on_top(t_stack *dest, t_node *node)
{
	t_node	*last;

	if (dest->head == NULL)
	{
		node->next = node;
		node->prev = node;
		dest->head = node;
		dest->size = 1;
	}
	else
	{
		last = dest->head->prev;
		node->next = dest->head;
		node->prev = last;
		last->next = node;
		dest->head->prev = node;
		dest->head = node;
		dest->size++;
	}
}

static int	move_top_node(t_stack *dest, t_stack *src)
{
	t_node	*node;

	node = pop_top_node(src);
	if (!node)
		return (0);
	push_on_top(dest, node);
	return (1);
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	if (move_top_node(stack_a, stack_b))
		write(1, "pa\n", 3);
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	if (move_top_node(stack_b, stack_a))
		write(1, "pb\n", 3);
}
