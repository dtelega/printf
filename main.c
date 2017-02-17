/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:10:20 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/17 17:30:28 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ftprintf.h"

int		ft_printf(const char *format, ...);

int		main(int ac, char **av)
{
	int		ft_p = 0;
	int		p;
	p = 0;
	char    *s;
	s = "hello world\n";
	long int li;
	li = 9;
		
	if (ac == 0 || av == 0)
		return (0);
	int i;
	i = -1009987;

	ft_p = ft_printf("% d\n", -42);
	p =       printf("hello [%d] here d\n", 0);
	printf("ft_p = %i\n   p = %i\n", ft_p, p);
	return 0;
}
