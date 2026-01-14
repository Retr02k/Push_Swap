/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:12:04 by psilva-p          #+#    #+#             */
/*   Updated: 2025/12/05 16:05:34 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

# define DEC "0123456789"
# define HEX "0123456789abcdef"
# define HEX_CAP "0123456789ABCDEF"
# define BIT_MASK 0x00000000ffffffff

typedef enum e_type
{
	POINTER,
	NB,
	STR,
}	t_type;

int	ft_printf(const char *s, ...);

#endif
