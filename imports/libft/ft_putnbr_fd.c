/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:20:16 by psilva-p          #+#    #+#             */
/*   Updated: 2025/10/31 18:37:33 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	long	num;
	char	buffer[12];

	if (fd < 0)
		return ;
	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	i = 0;
	if (num == 0)
		buffer[i++] = '0';
	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (--i >= 0)
		write(fd, &buffer[i], 1);
}
