/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:48:01 by psilva-p          #+#    #+#             */
/*   Updated: 2025/11/12 16:55:46 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_c_present(const char *s, const char *c)
{
	while (*s)
	{
		if (*s == *c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	length;
	char	*trm_str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_c_present(set, &s1[start]))
		start++;
	while (end > start && ft_c_present(set, &s1[end - 1]))
		end--;
	length = (end - start) + 1;
	trm_str = (char *)ft_calloc(length, sizeof(char));
	if (!trm_str)
		return (NULL);
	ft_strlcpy(trm_str, &s1[start], length);
	return (trm_str);
}
