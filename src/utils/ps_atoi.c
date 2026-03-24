/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:11:39 by psilva-p          #+#    #+#             */
/*   Updated: 2026/03/24 14:59:56 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "utils.h"

int	is_space(char str)
{
	return ((str == ' ') || (str >= '\t' && str <= '\r'));
}

static t_err	accumulate_digit(long *value, int digit, long sign)
{
	long	limit;

	limit = INT_MAX;
	if (sign == -1)
		limit = (long)INT_MAX + 1;
	if (*value > limit / 10 || (*value == limit / 10 && digit > (limit % 10)))
		return (ERR_OVERFLOW);
	*value = (*value * 10) + digit;
	return (OK);
}

t_err	ps_atoi(char	**next_ptr, char	*str, int	*result)
{
	long	sign;
	long	value;
	t_err	status;

	value = 0;
	while (is_space(*str))
		str++;
	sign = (*str != '-') - (*str == '-');
	str += (*str == '+') || (*str == '-');
	if (!(*str >= '0' && *str <= '9'))
		return (ERR_NON_INT);
	while (*str >= '0' && *str <= '9')
	{
		status = accumulate_digit(&value, *str - '0', sign);
		if (status != OK)
			return (status);
		str++;
	}
	*next_ptr = str;
	*result = value * sign;
	return (OK);
}
