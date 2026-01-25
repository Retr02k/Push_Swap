/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:08:42 by psilva-p          #+#    #+#             */
/*   Updated: 2025/11/17 18:36:13 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	nmemb, size_t	size)
{
	size_t	total;
	void	*mem;

	if (nmemb && size && nmemb > SIZE_MAX / size)
		return (NULL);
	total = nmemb * size;
	mem = malloc(total);
	if (!mem)
		return (NULL);
	ft_bzero(mem, total);
	return (mem);
}
