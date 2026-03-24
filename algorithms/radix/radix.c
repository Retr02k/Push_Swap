/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:48:32 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/24 15:52:47 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include "algorithms.h"
#include "moves.h"

void	radix(t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	bit_pos;
	unsigned int	max_bits;

	if (stack_is_sorted(stack_a))
		return ;
	bit_pos = 0;
	max_bits = count_bits(stack_a->size - 1);
	while (bit_pos < max_bits)
	{
		radix_pass(stack_a, stack_b, stack_a->size, bit_pos);
		bit_pos++;
	}
}
