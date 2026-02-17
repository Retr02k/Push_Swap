/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:06:18 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/17 19:05:59 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	swap_a(t_stack	*stack_a)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*third_node;
	t_node	*last_node;

	if (stack_a->head == NULL || stack_a->head->next == stack_a->head)
		return ;
	first_node = stack_a->head;
	second_node = first_node->next;
	third_node = second_node->next;
	last_node = first_node->prev;
	second_node->prev = last_node;
	second_node->next = first_node;
	first_node->next = third_node;
	first_node->prev = second_node;
	last_node->next = second_node;
	third_node->prev = first_node;
	stack_a->head = second_node;
}
