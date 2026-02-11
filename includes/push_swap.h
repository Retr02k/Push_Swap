/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:26:22 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/08 19:21:35 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "algorithms.h"
# include "checker.h"
# include "parsing.h"
# include "stack.h"
# include "utils.h"
//# include "ft_printf.h"
//# include "libft.h"

# include <limits.h>
# include <stdlib.h>

// Node in the linked list
typedef struct s_node
{
	int	value;
	int	index;				// for radix sort coordinate compression
	struct s_node *next;
}	t_node;

// Stack wreapper
typedef struct s_stack
{
	t_node	*top;			// head of the linked list
	int		size;			// number of elements
}	t_stack;

// Instructions (for bonus checker only, sperate file)
typedef struct s_instruction
{
	char					inst[4];
	struct s_instruction	*next;
} t_instruction;



#endif