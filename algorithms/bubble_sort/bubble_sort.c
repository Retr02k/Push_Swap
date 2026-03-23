/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:59:13 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/20 15:28:21 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

void	swap(int *i, int *j)
{
	int	temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

void	bubble_sort(int	*array, int numbers)
{
	int		i;
	int		j;
	bool	swapped;

	i = 0;
	while (i < numbers - 1)
	{
		swapped = false;
		j = 0;
		while (j < numbers - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = true;
			}
			j++;
		}
		if (swapped == false)
			break ;
		i++;
	}
}
