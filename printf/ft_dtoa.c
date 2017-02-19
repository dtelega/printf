/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:32:28 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/12 16:30:28 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char		*get_float_part(double num, size_t n)
{
	size_t	i;
	char	*res;

	res = ft_strnew(n);
	i = 0;
	while (i < n)
	{
		num = num * 10;
		res[i++] = (int)num + '0';
		num = num - (int)num;
	}
	return (res);
}

char			*ft_dtoa(double num, size_t n)
{
	t_dtoa	dtoa;

	dtoa.ipart = (size_t)num;
	if (n == 0)
		return (ft_itoa(dtoa.ipart));
	dtoa.result = ft_itoa(dtoa.ipart);
	dtoa.temp = ft_strjoin(dtoa.result, ".");
	free(dtoa.result);
	dtoa.fstr = get_float_part(num - (int)num, n);
	dtoa.result = ft_strjoin(dtoa.temp, dtoa.fstr);
	free(dtoa.temp);
	free(dtoa.fstr);
	return (dtoa.result);
}
