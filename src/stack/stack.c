/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:49:41 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/20 10:53:55 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include "utils.h"

t_stack	*stack_a_init(int ac, char **av)
{
	t_stack	*stack_a;
	t_node	*new_node;
	int		i;
	int		result;
	t_err	status;

	stack_a = malloc(sizeof(t_stack));
	stack_a->head = NULL;
	stack_a->size = 0;
	if (!stack_a)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		status = ps_atoi(&av[i], av[i], &result);
		if (status != OK)
			return (free(stack_a), NULL);
		else
		{
			new_node = create_node(result, 0);
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
