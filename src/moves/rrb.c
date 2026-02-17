/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:54:29 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/17 18:56:27 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	reverse_rotate_b(t_stack	*stack_b)
{
	if (stack_b->head == NULL || stack_b->head->next == stack_b->head)
		return ;
	stack_b->head = stack_b->head->prev;
}
