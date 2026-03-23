/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:55:10 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/20 11:14:17 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include "algorithms.h"
#include "moves.h"

int	stack_is_sorted(t_stack	*stack)
{
	t_node	*current;
	int		count;

	current = stack->head;
	if (current == NULL || stack->size < 2)
		return (1);
	count = 0;
	while (count < stack->size - 1)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
		count++;
	}
	return (1);
}

int	count_zero_bits(t_stack *stack_a, int bit_position)
{
	t_node	*current;
	int		counter;
	int		i;

	counter = 0;
	current = stack_a->head;
	i = 0;
	while (i < stack_a->size)
	{
		if (!((current->index >> bit_position) & 1))
			counter++;
		current = current->next;
		i++;
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
	while (bits_processed++ < original_size)
	{
		if ((stack_a->head->index >> bit_position) & 1)
			rotate_a(stack_a);
		else
			push_b(stack_a, stack_b);
	}
	while (stack_b->size > 0)
		push_a(stack_a, stack_b);
	bit_position++;
}
