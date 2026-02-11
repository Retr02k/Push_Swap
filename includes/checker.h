/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 21:26:55 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/11 21:31:13 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define	CHECKER_H

# include "push_swap.h"
typedef struct s_instruction
{
	char					inst[4];
	struct s_instruction	*next;
} t_instruction;



#endif
