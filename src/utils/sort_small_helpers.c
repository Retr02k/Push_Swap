/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:22:23 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/23 18:23:01 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "moves.h"
#include <unistd.h>

void	op_sa(t_stack *stack_a)
{
	swap_a(stack_a);
	write(1, "sa\n", 3);
}

void	op_rra(t_stack *stack_a)
{
	reverse_rotate_a(stack_a);
	write(1, "rra\n", 4);
}

static int	find_smallest_pos(t_stack *stack)
{
	t_node	*current;
	int		min_index;
	int		min_pos;
	int		i;

	current = stack->head;
	min_index = current->index;
	min_pos = 0;
	i = 0;
	while (i < stack->size)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

void	push_smallest_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;
	int	i;

	pos = find_smallest_pos(stack_a);
	if (pos <= stack_a->size / 2)
	{
		i = 0;
		while (i++ < pos)
			rotate_a(stack_a);
	}
	else
	{
		i = 0;
		while (i++ < (stack_a->size - pos))
			op_rra(stack_a);
	}
	push_b(stack_a, stack_b);
}
