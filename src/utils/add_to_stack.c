/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:43:11 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/13 14:00:08 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void add_node_to_stack(t_stack *stack, t_node *new_node)
{
	t_node	*last_node;
	
	if (stack->head == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		stack->head = new_node;
		stack->size = 1;
	}
	else
	{
		last_node = stack->head->prev;
		new_node->next = stack->head;
		new_node->prev = last_node;
		last_node->next = new_node;
		stack->head->prev = new_node;
		stack->size++;
	}
}
