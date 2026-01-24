/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                           "         +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:25:43 by psilva-p          #+#    #+#             */
/*   Updated: 2026/01/12 18:25:43 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	i;
	int	*values;

	if (ac > 1)
	{
		values = malloc(sizeof(int) * (ac - 1));
		i = 0;
		while (i < ac - 1)
		{
			values[i] = input_validation(av[i + 1]);
			i++;
		}
		if (is_dup(values, ac - 1))
		{
			ft_printf("Error\n");
			free(values);
			return (1);
		}
		free(values);
	}
	return (0);
}
