/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 19:41:22 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/19 13:28:29 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char		*ft_itoa_ll(long long int n)
{
	unsigned long long int	nb;
	size_t					len;
	char					*str;
	int						check_for_neg;

	nb = n;
	len = ft_llintlen(n);
	check_for_neg = 0;
	if (n < 0)
	{
		check_for_neg = 1;
	}
	if (!(str = (char *)malloc((len + 1) * sizeof(*str))))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (check_for_neg == 1)
		str[0] = '-';
	return (str);
}
