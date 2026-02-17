/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:37:38 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/17 19:06:03 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	swap_b(t_stack *stack_b)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*third_node;
	t_node	*last_node;

	if (stack_b->head == NULL || stack_b->head->next == stack_b->head)
		return ;
	first_node = stack_b->head;
	second_node = first_node->next;
	third_node = second_node->next;
	last_node = first_node->prev;
	second_node->prev = last_node;
	second_node->next = first_node;
	first_node->next = third_node;
	first_node->prev = second_node;
	last_node->next = second_node;
	third_node->prev = first_node;
	stack_b->head = second_node;	
}
