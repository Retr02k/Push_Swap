/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:40:01 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/17 18:56:30 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	reverse_rotate_a(t_stack	*stack_a)
{
	if (stack_a->head == NULL || stack_a->head->next == stack_a->head)
		return ;
	stack_a->head = stack_a->head->prev;
}
