/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_node_to_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:22:34 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/18 18:06:50 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/utils.h"
#include <stdio.h>

void	*extract_values(t_stack *stack_a)
{
	t_node	*current;
	int		*array;
	int		i;

	array = malloc(sizeof(int) * stack_a->size);
	if (!array)
		return (NULL);
	i = 0;
	current = stack_a->head;
	while (i < stack_a->size)
	{
		array[i] = current->value;
		current = current->next;
		i++;
	}
	return ((int *)array);
}

void	check_index_in_values(stack_a)
{
	
}










// int main()
// {
// 	t_stack a = {NULL, 2};
// 	t_node *b = create_node(3, 0);
// 	t_node *c = create_node(10, 0);
// 	add_node_to_stack(&a, b);
// 	add_node_to_stack(&a, c);

// 	int *gabriel = extract_values(&a);
// 	printf("%i\n", gabriel[0]);
// 	printf("%i\n", gabriel[1]);
// }
