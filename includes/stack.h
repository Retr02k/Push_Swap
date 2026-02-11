/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:49:55 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/11 21:30:29 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include "push_swap.h"

typedef struct s_node t_node;
typedef struct s_stack t_stack;

t_stack *stack_a_init(int ac, char **av);
t_stack	*stack_b_init(void);


#endif