/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:41:52 by psilva-p          #+#    #+#             */
/*   Updated: 2025/11/12 16:55:06 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	*ft_free(char **s, size_t size)
{
	size_t	counter;

	counter = 0;
	while (counter < size)
		free(s[counter++]);
	free(s);
	return (NULL);
}

static int	word_alloc(const char *s, char c, char **result)
{
	size_t	i;
	size_t	j;
	size_t	word_len;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		word_len = 0;
		while (s[i + word_len] && s[i + word_len] != c)
			word_len++;
		result[j] = ft_substr(s, i, word_len);
		if (!result[j])
		{
			ft_free(result, j);
			return (-1);
		}
		j++;
		i += word_len;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!result)
		return (NULL);
	if (word_alloc(s, c, result) == -1)
		return (NULL);
	return (result);
}
