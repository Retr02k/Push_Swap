/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:11:39 by psilva-p          #+#    #+#             */
/*   Updated: 2026/01/26 17:45:53 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

// char	test_overflow(int sign, int res, int next)
// {
// 	long aux;

// 	aux = ((long)res * 10) + next;
// 	if(sign == 1 && aux > INT_MAX)
// 		return (-1);
// 	else if (sign == -1 && aux > ((long)INT_MIN * -1))
// 		return (-1);
// 	return (0);
// }

int is_space(char str)
{
	return((str  == ' ') || (str >= '\t' && str <= '\r'));
}

int	ps_atoi(char	**list,  char	*str)
{
	long	sig;
	long	res;

	res = 0;
	while(is_space(*str))
		str++;
	sig = (*str != '-') - (*str == '-');
	str += (*str == '+') || (*str == '-');
	if (!(*str >= '0' && *str <= '9'))
		return (**list = 'E', 0);
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (*str++ - '0');
	if (res > INT_MAX || (res * sig < INT_MIN))
		**list = 'E';
	if (*str && !(is_space(*str)))
		**list = 'E';
	*list = str;
	return (res * sig);
}

int main(int ac, char **av)
{
	int i = 1;
	char *ptr;

	while (i < ac)
	{
		ptr = av[i];
		while (*ptr)
		{
			printf("Parsing: %s -> %i\n", ptr, ps_atoi(&ptr, ptr));
			while(*ptr && is_space(*ptr))
				ptr++;
		}
		i++;
	}
	return 0;
}
