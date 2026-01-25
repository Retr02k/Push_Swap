/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 00:13:55 by psilva-p          #+#    #+#             */
/*   Updated: 2026/01/24 17:07:16 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	is_dup(int	*array, int size)
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
				return (1);
			j++;
		}
		i++;
	}
	return	(0);
}