/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 19:03:36 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/23 18:53:49 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include "moves.h"
#include <unistd.h>

void	reverse_rotate_both(t_stack	*stack_a, t_stack	*stack_b)
{
	if (stack_a->head != NULL && stack_a->head->next != stack_a->head)
		stack_a->head = stack_a->head->prev;
	if (stack_b->head != NULL && stack_b->head->next != stack_b->head)
		stack_b->head = stack_b->head->prev;
	write(1, "rrr\n", 4);
}
