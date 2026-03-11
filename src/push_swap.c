/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:25:43 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/11 16:26:38 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "utils.h"
#include "algorithms.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return 0;
	else if (ac <= 5)
		sort_small();
	else
	{
		stack_a = stack_a_init(ac, av);
		stack_b = stack_b_init();
		if (!stack_a || is_dup())
		{
			write(2, "Error!\n", 8);
			exit(EXIT_FAILURE);
		}
		else if (stack_is_sorted(stack_a))
		{
			free(stack_a);
			free(stack_b);
			exit(EXIT_SUCCESS);
		}
		else
			radix(stack_a, stack_b);
	}
}
