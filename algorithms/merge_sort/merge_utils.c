/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:01:03 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/18 20:04:06 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

int	*create_temp_array(int	size)
{
	int	*tmp_arr;

	tmp_arr = malloc(sizeof(int) * size);
	if (!tmp_arr)
		return (NULL);
	return (tmp_arr);
}

void	copy_array(int	*tmp_array, int	*array, int	size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tmp_array[i] = array[i];
		i++;
	}
	
}

void	merge_sorted_halves(){}

void	copy_remaining(){}
