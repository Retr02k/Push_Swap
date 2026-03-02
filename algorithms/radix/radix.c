/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:48:32 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/02 21:38:49 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/utils.h"
#include "../../includes/algorithms.h"
#include "../../includes/moves.h"

void	radix(t_stack *stack_a, t_stack *stack_b)
{
	int		bit;
	int		original_size;
	int		bits_processed;

	bit = 0;
	while (bit < 9)
	{
		original_size = stack_a->size;
		bits_processed = 0;
		while (bits_processed < original_size)
		{
			if ((stack_a->head->index >> bit) & 1)
				rotate_a(stack_a);
			else
				push_b(stack_a, stack_b);
			bits_processed++;
		}
		while (stack_b->size > 0)
			push_a(stack_a, stack_b);
		bit++;
	}
}