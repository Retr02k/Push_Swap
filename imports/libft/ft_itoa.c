/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:49:11 by psilva-p          #+#    #+#             */
/*   Updated: 2025/11/12 16:53:42 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	int_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*handle_zero(void)
{
	char	*str;

	str = (char *)ft_calloc(2, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	return (str);
}

static	void	fill_string(char *str, int n, int i, int is_negative)
{
	if (is_negative)
	{
		while (n != 0)
		{
			str[i] = -(n % 10) + '0';
			n /= 10;
			i--;
		}
	}
	else
	{
		while (n > 0)
		{
			str[i] = (n % 10) + '0';
			n /= 10;
			i--;
		}
	}
}

char	*ft_itoa(int n)
{
	int		size;
	int		is_negative;
	char	*str;

	if (n == 0)
		return (handle_zero());
	is_negative = (n < 0);
	size = int_count(n) + 1;
	str = (char *)ft_calloc(size, sizeof(char));
	if (!str)
		return (NULL);
	if (is_negative)
		str[0] = '-';
	fill_string(str, n, size - 2, is_negative);
	return (str);
}
