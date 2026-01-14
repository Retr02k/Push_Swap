/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 09:18:02 by psilva-p          #+#    #+#             */
/*   Updated: 2025/11/12 16:54:35 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		counter;
	t_list	*temp_lst;

	if (!lst)
		return (0);
	counter = 0;
	temp_lst = lst;
	while (temp_lst)
	{
		temp_lst = temp_lst->next;
		counter++;
	}
	return (counter);
}
