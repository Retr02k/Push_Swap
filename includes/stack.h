/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:49:55 by psilva-p          #+#    #+#             */
/*   Updated: 2026/01/24 20:19:11 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_node t_node;
typedef struct s_stack t_stack;

t_node	*new_node(int value);
t_stack *stack_init(int *values, int size);

t_node	*new_node(int value);
t_stack	*stack_init(int *values, int size);
void	stack_free(t_stack **s);
void	stack_push(t_stack *s, int value);
int		stack_pop(t_stack *s, int *out);


#endif