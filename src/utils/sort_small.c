/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:22:09 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/24 13:03:24 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "moves.h"

static void	sort_three(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->head->index;
	b = stack_a->head->next->index;
	c = stack_a->head->next->next->index;
	if (a < b && b < c)
		return ;
	if (a > b && b < c && a < c)
		op_sa(stack_a);
	else if (a > b && b > c)
	{
		op_sa(stack_a);
		op_rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stack_a);
	else if (a < b && b > c && a < c)
	{
		op_sa(stack_a);
		rotate_a(stack_a);
	}
	else
		op_rra(stack_a);
}

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || stack_a->size < 2 || stack_is_sorted(stack_a))
		return ;
	if (stack_a->size == 2)
	{
		if (stack_a->head->index > stack_a->head->next->index)
			op_sa(stack_a);
		return ;
	}
	while (stack_a->size > 3)
		push_smallest_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (stack_b->size > 0)
		push_a(stack_a, stack_b);
}
