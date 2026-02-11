/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:11:39 by psilva-p          #+#    #+#             */
/*   Updated: 2026/02/11 16:56:55 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include "../../includes/utils.h"

int is_space(char str)
{
	return((str  == ' ') || (str >= '\t' && str <= '\r'));
}
// Parse each argument
t_err	ps_atoi(char	**list,  char	*str, int	*result)
{
	long	sig;
	long	res;

	res = 0;
	while(is_space(*str))
		str++;
	sig = (*str != '-') - (*str == '-');
	str += (*str == '+') || (*str == '-');
	if (!(*str >= '0' && *str <= '9'))
		return (ERR_NON_INT);
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (*str++ - '0');
	if ((sig == 1 && res > INT_MAX) || (sig == -1 && (res * sig < INT_MIN)))
		return (ERR_OVERFLOW);
	*list = str;
	*result = res * sig;
	return (OK);
}

// int main(int ac, char **av)
// {
// 	int i = 1;
// 	int result;
// 	char *ptr;
// 	t_err status;

// 	while (i < ac)
// 	{
// 		ptr = av[i];
// 		while (*ptr)
// 		{
// 			status = ps_atoi(&ptr, ptr, &result);
// 			if (status == OK)
// 				printf("Parsed: %d\n", result);
// 			else
// 			{
// 				printf("Error: %d\n", status);
// 				break;
// 			}
// 		}
// 		i++;
// 	}
// 	return 0;
// }
