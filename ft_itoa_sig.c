/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_sig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:58:40 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/17 19:06:35 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char	*ft_itoa_sig(signed char n)
{
	int		nb;
	size_t	len;
	char	*str;
	int		check_neg;

	nb = n;
	len = ft_intlen(nb);
	check_neg = 0;
	if (nb < 0)
	{
		nb *= -1;
		check_neg = 1;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (check_neg == 1)
		str[0] = '-';
	return (str);
}
