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

int main (int	ac, char	**av)
{
	int i;
	int gabriel;

	i = 1;
	while (i < ac)
	{
		gabriel = ft_atoi(av[i]);
		ft_printf("%i\n", gabriel);
		i++;
	}
	return (0);
}