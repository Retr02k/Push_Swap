/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:26:22 by psilva-p          #+#    #+#             */
/*   Updated: 2026/01/24 00:49:09 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../imports/printf/ft_printf.h"
#include <limits.h>
#include <stdlib.h>


// Node metadata for advanced sorting algorithms
typedef struct s_node
{
	int	value;		// actual integer value
	int	index;		// compressed index for radix sort or move cost for Turkish algorithm
	struct s_node *next;
}	t_node;

typedef struct s_instruction
{
	char inst[4];
	struct s_instruction *next;
} t_instruction;


// Stack structure using dynamic array
typedef struct s_stack
{
	t_instruction	*moves; 	// array with the sequence of instructions 
	int				size;		// current number of elements
	int				capacity_a;	// allocated space
	int				capacity_b;
	t_node			*stack_a;
	t_node			*stack_b;
}	t_stack;

int	ft_atoi(const char	*str, int *res);
int input_validation(const char	*arg);
char	is_dup(char	*s1, char *s2);


#endif