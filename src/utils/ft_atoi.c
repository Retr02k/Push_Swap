/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:11:39 by psilva-p          #+#    #+#             */
/*   Updated: 2026/01/24 00:15:16 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char parse_trailing_chars(const char **s)
{
	int sign;
	const char *str;

	str = *s;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	*s = str;
	return(sign);
}

char	test_overflow(int sign, int res, int next)
{
	long aux;

	aux = ((long)res * 10) + next;
	if(sign == 1 && aux > INT_MAX)
		return (-1);
	else if (sign == -1 && aux > ((long)INT_MIN * -1))
		return (-1);
	return (0);
}

int	ft_atoi(const char	*str, int *res)
{
	int	sign;
	int	type;

	*res = 0;
	type = 0;
	sign = parse_trailing_chars(&str);
	while (*str >= '0' && *str <= '9')
	{
		if (test_overflow(sign, *res, *str - '0'))
			return (-1);
		type = 1;
		*res *= 10;
		*res += *str - '0';
		str++;
	}
	if (!type)
		return (-1);
	while (*str)
	{
		if (*str  != ' ' && !(*str >= '\t' && *str <= '\r'))
			return (-1);
		str++;
	}
	return (0);
}
