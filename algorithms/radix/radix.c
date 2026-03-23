/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:48:32 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/20 15:25:49 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include "algorithms.h"
#include "moves.h"

int	handle_special_bit_cases(t_stack *stack_a, t_stack *stack_b, int zeros)
{
	if (zeros == 0)
		return (1);
	if (zeros == stack_a->size)
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
	unsigned int	bit;
	int				zeros;
	unsigned int	max_bits;

	if (stack_is_sorted(stack_a))
		return ;
	bit = 0;
	max_bits = bit_counter(stack_a->size - 1);
	while (bit < max_bits)
	{
		zeros = count_zero_bits(stack_a, bit);
		if (!handle_special_bit_cases(stack_a, stack_b, zeros))
			radix_engine(stack_a, stack_b, stack_a->size, bit);
		bit++;
	}
}
