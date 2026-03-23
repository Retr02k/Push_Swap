/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:53:14 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/20 10:36:20 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include "push_swap.h"

void			*extract_values(t_stack *stack_a);
void			swap(int *i, int *j);
void			bubble_sort(int	*array, int numbers);
int				stack_is_sorted(t_stack	*stack);
int				count_zero_bits(t_stack *stack_a, int bit_position);
unsigned int	bit_counter(unsigned int index);
void			radix_engine(t_stack *stack_a, t_stack	*stack_b, int original_size, int bit_position);
void			radix(t_stack *stack_a, t_stack *stack_b);
int				handle_special_bit_cases(t_stack *stack_a, t_stack *stack_b, int zeros);
void			check_index_in_values(t_stack *stack_a);

#endif