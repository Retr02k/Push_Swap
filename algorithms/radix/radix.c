/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:48:32 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/24 13:11:15 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include "algorithms.h"
#include "moves.h"

int	handle_uniform_bit_pass(t_stack *stack_a,
		t_stack *stack_b,
		int zero_count)
{
	if (zero_count == 0)
		return (1);
	if (zero_count == stack_a->size)
	{
		while (stack_a->size > 0)
			push_b(stack_a, stack_b);
		while (stack_b->size > 0)
			push_a(stack_a, stack_b);
		return (1);
	}
	return (0);
}

void	radix(t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	bit_pos;
	int				zero_count;
	unsigned int	max_bits;

	if (stack_is_sorted(stack_a))
		return ;
	bit_pos = 0;
	max_bits = count_bits(stack_a->size - 1);
	while (bit_pos < max_bits)
	{
		zero_count = count_zero_bits(stack_a, bit_pos);
		if (!handle_uniform_bit_pass(stack_a, stack_b, zero_count))
			radix_pass(stack_a, stack_b, stack_a->size, bit_pos);
		bit_pos++;
	}
}
