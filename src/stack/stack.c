/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:49:41 by psilva-p          #+#    #+#             */
/*   Updated: 2026/01/24 23:16:10 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

t_stack *stack_init(int *values, int size)	// Initializes the stack with he parsed values
{
	t_stack	*stack;
	int		i;
	t_node	*node;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	if (!values || size <= 0)
		return(stack);
	i = size - 1;
	while (i >= 0)
	{
		node = new_node(values[i]);
		if (!node)
			return (NULL);
		node->next = stack->top;
		stack->top = node;
		stack->size++;
		i--;
	}
	return (stack);
}

void	stack_free(t_stack **s)				// Cleanup and free all memory
{
	
}
void	stack_push(t_stack *s, int value)	// Add element to top element
{

}

int		stack_pop(t_stack *s, int *out)		// Remove and return top element
{
	
}