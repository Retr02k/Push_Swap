/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:01:46 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/18 20:02:44 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

void	divide(int	*array, int	start, int	end)
{
	int	mid;

	if (start >= end)
		return ;
	mid = (start + end) / 2;
	divide(array, start, mid);
	divide(array, mid + 1, end);

}

void	merge(int	*array, int	start, int	mid, int	end)
{
	int	*left_array;
	int	*right_array;
	int	left_size;
	int	right_size;
	int	i;
	int	j;

	left_size = mid - start + 1;
	right_size = end - mid;
	left_array = create_temp_array(left_size);
	right_array = create_temp_array(right_size);
	i = 0;
	while (i < left_size)
	{
		left_array[i] = array[start + i];
		i++;
	}
	j = 0;
	while (j < right_size)
	{
		right_array[j] = array[mid + 1 + j];
		j++;
	}
	i = 0;
	j = 0;
	
}

void	merge_sort(){}

