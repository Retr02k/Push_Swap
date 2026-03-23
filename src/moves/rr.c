/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:37:52 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/23 18:53:48 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include "moves.h"
#include <unistd.h>

void	rotate_both(t_stack	*stack_a, t_stack	*stack_b)
{
	if (stack_a->head != NULL && stack_a->head->next != stack_a->head)
		stack_a->head = stack_a->head->next;
	if (stack_b->head != NULL && stack_b->head->next != stack_b->head)
		stack_b->head = stack_b->head->next;
	write(1, "rr\n", 3);
}
