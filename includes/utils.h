/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:06:24 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/11 21:31:01 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "push_swap.h"
typedef enum error_type
{
	OK,
	ERR_NON_INT,
	ERR_OVERFLOW,
	ERR_DUP,
}	t_err;


int		is_dup(int	*array, int size);
t_err	ps_atoi(char	**list,  char	*str, int	*result);
t_node *create_node(int value, int index);
void add_node_to_stack(t_stack *stack, t_node *new_node);




#endif