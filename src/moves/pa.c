/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:06:27 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/16 18:48:06 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;
	t_node	*second_node;
	t_node	*last_node;

	if (stack_b->head == NULL)
		return ;
	tmp = stack_b->head;
	if (tmp->next == tmp)
	{
		stack_b->head = NULL;
		add_node_to_stack(stack_a, tmp);
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
		add_node_to_stack(stack_a, tmp);
		stack_b->size--;
		stack_a->size++;
	}
}
