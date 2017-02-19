/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_i_get_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:14:14 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/19 13:27:49 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char	*d_i_get_s(va_list *args, t_specifer *specifer)
{
	char	*s;
	char	*res;
	int		nb;

	if (!specifer->modify)
	{
		s = ft_itoa_l(va_arg(*args, int));
		if (s[0] == '-')
		{
			specifer->flag_plus = '-';
			s = ft_itoa_l(-ft_atoi_l(s));
		}
	}
	else if (specifer->modify == 'l')
	{
		s = ft_itoa_l(va_arg(*args, long int));
		if (s[0] == '-')
		{
			specifer->flag_plus = '-';
			s = ft_itoa_l(-ft_atoi_l(s));
		}
	}
	else if (specifer->modify == 'H')
	{
		s = ft_itoa_sig(va_arg(*args, signed int));
		if (s[0] == '-')
		{
			specifer->flag_plus = '-';
			s = ft_itoa(-ft_atoi(s));
		}
	}
	else if (specifer->modify == 'L')
	{
		s = ft_itoa_ll(va_arg(*args, long long));
		//if (s[0] == '-')
		//{
		//	specifer->flag_plus = '-';
		//	s = ft_itoa_ll(-ft_atoi_ll(s));
		//	}
	}
	else if (specifer->modify == 'h')
	{
		nb = va_arg(*args, int);
		if (nb >= 32768)
		{
			nb *= -1;
			while (nb > -32768)
				nb++;
		}
		s = ft_itoa(nb);
		if (s[0] == '-')
		{
			specifer->flag_plus = '-';
			s = ft_itoa(-ft_atoi(s));
		}
	}
	else if (specifer->modify == 'j' || specifer->modify == 'z')
		s = ft_itoa_base_lun(va_arg(*args, unsigned long long), 10);
	else
		s = NULL;
	res = ft_strnew(ft_strlen(s));
	res = ft_strcpy(res, s);
	return (res);
}
