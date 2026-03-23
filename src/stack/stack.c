/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:49:41 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/23 18:54:06 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include "utils.h"

static void	free_stack_nodes(t_stack *stack)
{
	t_node	*current;
	t_node	*next;
	int		i;

	if (!stack || !stack->head)
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
}

t_stack	*stack_a_init(int ac, char **av)
{
	t_stack	*stack_a;
	t_node	*new_node;
	int		i;
	int		result;
	t_err	status;

	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	stack_a->head = NULL;
	stack_a->size = 0;
	i = 1;
	while (i < ac)
	{
		status = ps_atoi(&av[i], av[i], &result);
		if (status != OK)
		{
			free_stack_nodes(stack_a);
			return (free(stack_a), NULL);
		}
		else
		{
			new_node = create_node(result, 0);
			if (!new_node)
			{
				free_stack_nodes(stack_a);
				return (free(stack_a), NULL);
			}
			add_node_to_stack(stack_a, new_node);
		}
		i++;
	}
	return (stack_a);
}

t_stack	*stack_b_init(void)
{
	t_stack	*stack_b;

	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		return (NULL);
	stack_b->head = NULL;
	stack_b->size = 0;
	return (stack_b);
}
