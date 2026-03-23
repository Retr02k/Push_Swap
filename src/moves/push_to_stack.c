/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:06:27 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/23 18:23:25 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include <unistd.h>

static int	push_to_stack(t_stack *dest, t_stack *src)
{
	t_node	*node;

	if (src->head == NULL)
		return (0);
	node = src->head;
	if (node->next == node)
		src->head = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		src->head = node->next;
	}
	add_node_to_stack(dest, node);
	src->size--;
	return (1);
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	if (push_to_stack(stack_a, stack_b))
		write(1, "pa\n", 3);
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	if (push_to_stack(stack_b, stack_a))
		write(1, "pb\n", 3);
}
