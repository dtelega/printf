/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_llun.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 12:43:54 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/18 13:08:02 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*res_llun(int i, int n, int *convert)
{
	char	*base;
	char	*res;

	base = "0123456789ABCDEF";
	res = (char *)malloc(i * sizeof(res));
	i--;
	while (i >= 0)
	{
		res[n] = base[convert[i]];
		n++;
		i--;
	}
	res[n] = '\0';
	return (res);
}

char		*ft_itoa_base_llun(unsigned long long int value, int base)
{
	long int	val;
	int			i;
	int			n;
	int			convert[64];

	val = value;
	n = 0;
	i = 0;
	if (val == 0)
		return ("0");
	while (val != 0)
	{
		convert[i++] = val % base;
		val = val / base;
	}
	return (res_llun(i, n, convert));
}
