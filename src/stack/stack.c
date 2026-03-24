/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:49:41 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/24 18:36:59 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include "utils.h"

static void free_stack_nodes(t_stack *stack)
{
	t_node *current;
	t_node *next;
	int i;

	if (!stack || !stack->head)
		return;
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

static t_stack *cleanup_and_null(t_stack *stack_a)
{
	free_stack_nodes(stack_a);
	free(stack_a);
	return (NULL);
}

static int parse_arg_and_push(t_stack *stack_a, char *arg)
{
	t_node *new_node;
	int value;
	t_err status;
	int parsed_any;

	parsed_any = 0;
	while (1)
	{
		while (is_space(*arg))
			arg++;
		if (*arg == '\0')
			return (parsed_any == 0);
		status = ps_atoi(&arg, arg, &value);
		if (status != OK)
			return (1);
		new_node = create_node(value, 0);
		if (!new_node)
			return (1);
		add_node_to_stack(stack_a, new_node);
		parsed_any = 1;
	}
}

t_stack *stack_a_init(int ac, char **av)
{
	t_stack *stack_a;
	int i;

	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	stack_a->head = NULL;
	stack_a->size = 0;
	i = 1;
	while (i < ac)
	{
		if (parse_arg_and_push(stack_a, av[i]))
			return (cleanup_and_null(stack_a));
		i++;
	}
	return (stack_a);
}

t_stack *stack_b_init(void)
{
	t_stack *stack_b;

	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		return (NULL);
	stack_b->head = NULL;
	stack_b->size = 0;
	return (stack_b);
}
