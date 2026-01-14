/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:51:58 by psilva-p          #+#    #+#             */
/*   Updated: 2025/12/05 16:07:03 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putnbr_base(unsigned long nb, char *base, int base_len)
{
	char	buffer[20];
	int		i;
	int		count;

	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	while (nb > 0)
	{
		buffer[i++] = base[nb % base_len];
		nb /= base_len;
	}
	count = i;
	while (--i >= 0)
		write (1, &buffer[i], 1);
	return (count);
}

static int	print_pointer_number(void *ptr, int nb, int type)
{
	unsigned long	addr;

	if (type == NB)
	{
		if (nb < 0)
		{
			write (1, "-", 1);
			nb *= -1;
			return (1 + putnbr_base(nb & BIT_MASK, DEC, 10));
		}
		return (putnbr_base(nb, DEC, 10));
	}
	else if (type == STR)
	{
		if (!ptr)
			return (write (1, "(null)", 6));
		while (((char *)ptr)[++nb])
			write (1, ((char *)ptr) + nb, 1);
		return (nb);
	}
	else if (!ptr)
		return (write (1, "(nil)", 5));
	addr = (unsigned long)ptr;
	return (write (1, "0x", 2) + putnbr_base(addr, HEX, 16));
}

int	ft_printf_rules(const char flag, va_list arg)
{
	char	c;

	if (flag == 'c')
	{
		c = va_arg(arg, int);
		return (write (1, &c, 1));
	}
	if (flag == 's')
		return (print_pointer_number (va_arg(arg, char *), -1, STR));
	if (flag == 'p')
		return (print_pointer_number (va_arg(arg, void *), 0, POINTER));
	if (flag == 'd' || flag == 'i')
		return (print_pointer_number (0, va_arg(arg, int), NB));
	if (flag == 'u')
		return (putnbr_base (va_arg(arg, unsigned int), DEC, 10));
	if (flag == 'x')
		return (putnbr_base (va_arg(arg, unsigned int), HEX, 16));
	if (flag == 'X')
		return (putnbr_base (va_arg(arg, unsigned int), HEX_CAP, 16));
	if (flag == '%')
		return (write(1, "%", 1));
	return (write(1, &flag, 1));
}
