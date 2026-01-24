/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:03:20 by psilva-p          #+#    #+#             */
/*   Updated: 2026/01/24 00:32:37 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int input_validation(const char	*arg)
{
	int	result;
	int gabriel;

	gabriel = ft_atoi(arg, &result);
	return (gabriel);	
}
