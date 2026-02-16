/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:06:27 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/16 17:43:05 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;
	t_node	*tmp2;
	t_node	*second_node;

	if (stack_b->head == NULL)
		return ;
	else
	{
		tmp = stack_b->head;
		tmp2 = stack_a->head;
		second_node = stack_b->head->next;
		if (tmp->next == tmp)
		{
			stack_b->head = NULL;
			stack_a->head = tmp;
			stack_a->head->prev = tmp2->prev;
			tmp2->prev->next = tmp2;
			stack_b->size--;
			stack_a->size++;
			return ;
		}
		stack_b->head = second_node;
		stack_b->head->prev = tmp->prev;
		tmp->prev->next = stack_b->head;
		if (stack_a->head == NULL)
		{
			stack_a->head = tmp;
		}
		stack_a->head = tmp;
		stack_a->head->prev = tmp2->prev;
		tmp2->prev->next = tmp2;
		stack_b->size--;
		stack_a->size++;
	}
}
