/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:10:20 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/21 20:05:43 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ftprintf.h"
#define LONG_MIN   (-2147483647L - 1)
#define LLONG_MIN  (-9223372036854775807LL - 1)
#define LLONG_MAX  9223372036854775807LL
#define SHRT_MAX   32767
#define SHRT_MIN   (-32767 - 1)
#define LONG_MAX   2147483647L
#define UCHAR_MAX 255
#define USHRT_MAX 0xFFFFU

int		ft_printf(const char *format, ...);

int		main(int ac, char **av)
{
	int		ft_p = 0;
	int		p;
	p = 0;
	char    *s;
	s = "hello world\n";
	long long int li;
	li = 9000000000000000000;
		
	if (ac == 0 || av == 0)
		return (0);
	int i;
	i = 1234;

	ft_p = ft_printf("%o\n", LONG_MAX);
	p =       printf("%o\n", LONG_MAX);
	printf("ft_p = %i\n   p = %i\n", ft_p, p);
	return (0);
}
