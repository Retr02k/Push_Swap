/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:45:03 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/23 18:54:01 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include "moves.h"
#include <unistd.h>

static void	swap_no_print(t_stack *stack)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*third_node;
	t_node	*last_node;

	if (stack->head == NULL || stack->head->next == stack->head)
		return ;
	first_node = stack->head;
	second_node = first_node->next;
	if (second_node->next == first_node)
	{
		stack->head = second_node;
		return ;
	}
	third_node = second_node->next;
	last_node = first_node->prev;
	second_node->prev = last_node;
	second_node->next = first_node;
	first_node->next = third_node;
	first_node->prev = second_node;
	last_node->next = second_node;
	third_node->prev = first_node;
	stack->head = second_node;
}

void	swap_both(t_stack	*stack_a, t_stack	*stack_b)
{
	swap_no_print(stack_a);
	swap_no_print(stack_b);
	write(1, "ss\n", 3);
}
