/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:06:24 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/08 22:47:23 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "push_swap.h"
typedef enum error_type
{
	OK,
	ERR_NON_INT,
	ERR_OVERFLOW,
	ERR_DUP,
}	t_err;


int		is_dup(int	*array, int size);
t_err	ps_atoi(char	**list,  char	*str, int	*result);



#endif