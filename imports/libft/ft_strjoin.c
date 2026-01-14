/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:41:33 by psilva-p          #+#    #+#             */
/*   Updated: 2025/11/12 16:55:23 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > SIZE_MAX - len2)
		return (NULL);
	total_len = len1 + len2;
	str = (char *)ft_calloc(total_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, (void *)s1, len1);
	ft_memcpy(str + len1, (void *)s2, len2);
	return (str);
}
