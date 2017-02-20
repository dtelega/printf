/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_i_get_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:14:14 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/20 19:58:03 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char	*d_i_get_s(va_list *args, t_specifer *specifer)
{
	char	*s;
	char	*res;

	if (!specifer->modify)
		s = ft_itoa_l(va_arg(*args, int));
	else if (specifer->modify == 'l')
		s = ft_itoa_l(va_arg(*args, long int));
	else if (specifer->modify == 'H')
		s = ft_itoa_base((signed char)va_arg(*args, long long), 10);
	else if (specifer->modify == 'L')
		s = ft_itoa_ll(va_arg(*args, long long));
	else if (specifer->modify == 'h')
		s = ft_itoa_base((short int)va_arg(*args, long long), 10);
	else if (specifer->modify == 'j')
		s = ft_itoa_ll((intmax_t)va_arg(*args, unsigned long long));
	else if (specifer->modify == 'z')
		s = ft_itoa_ll((size_t)va_arg(*args, unsigned long long));
	else
		s = NULL;
	if (s[0] == '-')
	{
		specifer->flag_plus = '-';
		s = rm_minus(s);
	}
	res = ft_strnew(ft_strlen(s));
	res = ft_strcpy(res, s);
	return (s);
}

char*	rm_minus(char *s)
{
	int		i;
	int		k;
	char	*res;

	res = ft_strnew(ft_strlen(s) - 1);
	i = 1;
	k = 0;
	while (s[i])
	{
		res[k] = s[i];
		k++;
		i++;
	}
	return (res);
}
