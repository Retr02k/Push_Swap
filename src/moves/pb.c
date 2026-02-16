/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:31:09 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/16 19:44:21 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	push_b(t_stack	*stack_a, t_stack	*stack_b)
{
	t_node	*tmp;
	t_node	*second_node;
	t_node	*last_node;

	if (stack_a->head == NULL)
		return ;
	tmp = stack_a->head;
	if (tmp->next == tmp)
	{
		stack_a->head = NULL;
		add_node_to_stack(stack_b, tmp);
		stack_a->size--;
		stack_b->size++;
	}
	else
	{
		second_node = stack_a->head->next;
		last_node = stack_a->head->prev;
		second_node->prev = last_node;
		last_node->next = second_node;
		stack_a->head = second_node;
		add_node_to_stack(stack_b, tmp);
		stack_a->size--;
		stack_b->size++;
	}
}
