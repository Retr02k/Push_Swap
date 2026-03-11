/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_node_to_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:22:34 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/10 17:57:39 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/utils.h"
#include "../../includes/algorithms.h"

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

void	check_index_in_values(t_stack *stack_a)
{
	t_node	*current;
	int		*array;
	int		i;

	array = extract_values(stack_a);
	bubble_sort(array, stack_a->size);
	current = stack_a->head;
	while (current)
	{
		i = 0;
		while (i < stack_a->size)
		{
			if (current->value == array[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
	free(array);
}
