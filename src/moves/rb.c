/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:34:53 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/17 18:37:24 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	rotate_b(t_stack	*stack_b)
{
	if (stack_b->head == NULL || stack_b->head->next == stack_b->head)
		return ;
	stack_b->head = stack_b->head->next;
}
