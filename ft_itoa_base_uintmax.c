/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uintmax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 13:06:55 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/18 13:12:12 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*res_uintmax(int i, int n, int *convert)
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

char	*ft_itoa_base_uintmax(uintmax_t value, int base)
{
	long long int	val;
	int				i;
	int				n;
	int				convert[64];

	val = value;
	n = 0;
	if (val < 0)
	{
		val *= -1;
		if (base == 10)
			n = 1;
	}
	i = 0;
	if (val == 0)
		return ("0");
	while (val != 0)
	{
		convert[i++] = val % base;
		val = val / base;
	}
	return (res_uintmax(i, n, convert));
}
