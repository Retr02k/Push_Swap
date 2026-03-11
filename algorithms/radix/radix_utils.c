/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:55:10 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/10 17:57:16 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/utils.h"
#include "../../includes/algorithms.h"
#include "../../includes/moves.h"

int	stack_is_sorted(t_stack	*stack)
{
	t_node	*current;

	current = stack->head;
	if (current == NULL)
		return (1);
	while (current != stack->head)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

int	count_zero_bits(t_stack *stack_a, int bit_position)
{
	t_node	*current;
	int		counter;

	counter = 0;
	current = stack_a->head;
	while (current != stack_a->head)
	{
		if (!((current->index >> bit_position) & 1))
			counter++;
		current = current->next;
	}
	return (counter);
}

unsigned int	bit_counter(unsigned int index)
{
	unsigned int	counter;

	counter = 0;
	while (index)
	{
		counter++;
		index >>= 1;
	}
	return (counter);
}

void	radix_engine(t_stack *stack_a, t_stack	*stack_b, int original_size, int bit_position)
{
	int	bits_processed;

	bits_processed = 0;
	while (bits_processed < original_size)
	{
		if ((stack_a->head->index >> bit_position) & 1)
			rotate_a(stack_a);
		else
			push_b(stack_a, stack_b);
		bits_processed++;
	}
	while (stack_b->size > 0)
		push_a(stack_a, stack_b);
	bit_position++;
}
