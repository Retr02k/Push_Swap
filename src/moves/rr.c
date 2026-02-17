/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:37:52 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/17 18:38:52 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include "moves.h"

void	rotate_both(t_stack	*stack_a, t_stack	*stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}
