/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:22:23 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/24 16:06:18 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "moves.h"

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
			reverse_rotate_a(stack_a);
	}
	push_b(stack_a, stack_b);
}
