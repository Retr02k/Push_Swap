/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:06:27 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/17 19:03:01 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*last_node;

	if (stack_b->head == NULL)
		return ;
	first_node = stack_b->head;
	if (first_node->next == first_node)
	{
		stack_b->head = NULL;
		add_node_to_stack(stack_a, first_node);
		stack_b->size--;
		stack_a->size++;
	}
	else
	{
		second_node = stack_b->head->next;
		last_node = stack_b->head->prev;
		second_node->prev = last_node;
		last_node->next = second_node;
		stack_b->head = second_node;
		add_node_to_stack(stack_a, first_node);
		stack_b->size--;
		stack_a->size++;
	}
}
