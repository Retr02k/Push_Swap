/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:46:55 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/17 17:53:14 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
#define	MOVES_H

#include "push_swap.h"
#include "utils.h"


void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack	*stack_a, t_stack	*stack_b);
void	swap_a(t_stack	*stack_a);
void	swap_b(t_stack *stack_b);
void	swap_both(t_stack	*stack_a, t_stack	*stack_b);


#endif