/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:52:13 by psilva-p          #+#    #+#             */
/*   Updated: 2025/11/12 16:55:51 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	length;
	size_t	available;
	size_t	copy_len;
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (start >= length)
		return ((char *)ft_calloc(1, sizeof(char)));
	available = length - start;
	copy_len = len;
	if (copy_len > available)
		copy_len = available;
	sub = (char *)ft_calloc(copy_len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < copy_len)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}
