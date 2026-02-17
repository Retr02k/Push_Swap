/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 00:13:55 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/17 18:52:05 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include <stdio.h>

int	is_dup(int	*array, int size)
{
	int	i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (ERR_DUP);
			j++;
		}
		i++;
	}
	return	(OK);
}

int main()
{
	int arr[] = {3, 5, 55, 90};

	int res = is_dup(arr, 4);
	printf("%i\n", res);
}