/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:04:23 by psilva-p          #+#    #+#             */
/*   Updated: 2025/12/05 16:05:55 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_rules(const char flag, va_list arg);

int	ft_printf(const char *s, ...)
{
	int		i;
	int		print;
	va_list	arg;

	va_start(arg, s);
	i = 0;
	print = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			print += ft_printf_rules(s[i + 1], arg);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			print++;
		}
		i++;
	}
	va_end(arg);
	return (print);
}
