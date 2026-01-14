/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:21:55 by psilva-p          #+#    #+#             */
/*   Updated: 2025/11/12 16:55:43 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		length;

	length = ft_strlen(s);
	str = (char *)(s + length);
	while (str >= s)
	{
		if (*str == (char) c)
			return (str);
		str--;
	}
	return (0);
}
