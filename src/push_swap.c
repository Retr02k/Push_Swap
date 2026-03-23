/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:25:43 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/20 10:52:48 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "utils.h"
#include "algorithms.h"
#include <unistd.h>

static void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;
	int		i;

	if (!stack)
		return ;
	current = stack->head;
	i = 0;
	while (current && i < stack->size)
	{
		next = current->next;
		free(current);
		current = next;
		i++;
	}
	free(stack);
}

static int	error_exit(t_stack *stack_a, t_stack *stack_b)
{
	write(2, "Error\n", 6);
	free_stack(stack_a);
	free_stack(stack_b);
	return (1);
}

static int	validate_duplicates(t_stack *stack_a)
{
	int	*values;
	int	status;

	values = (int *)extract_values(stack_a);
	if (!values)
		return (1);
	status = is_dup(values, stack_a->size);
	free(values);
	if (status != OK)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = stack_a_init(ac, av);
	stack_b = stack_b_init();
	if (!stack_a || !stack_b)
		return (error_exit(stack_a, stack_b));
	if (validate_duplicates(stack_a))
		return (error_exit(stack_a, stack_b));
	check_index_in_values(stack_a);
	if (!stack_is_sorted(stack_a))
		radix(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
