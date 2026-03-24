/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:53:14 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/24 16:06:27 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include "push_swap.h"

void			*extract_values(t_stack *stack_a);
void			swap(int *i, int *j);
void			bubble_sort(int	*array, int numbers);
int				stack_is_sorted(t_stack	*stack);
unsigned int	count_bits(unsigned int index);
void			radix_pass(t_stack *stack_a,
					t_stack	*stack_b,
					int original_size,
					int bit_position
					);
void			radix(t_stack *stack_a, t_stack *stack_b);
void			sort_small(t_stack *stack_a, t_stack *stack_b);
void			push_smallest_to_b(t_stack *stack_a, t_stack *stack_b);
void			check_index_in_values(t_stack *stack_a);

#endif