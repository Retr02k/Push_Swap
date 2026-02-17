/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 19:03:36 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/17 19:05:52 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include "moves.h"

void	reverse_rotate_both(t_stack	*stack_a, t_stack	*stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}
