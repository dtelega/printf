/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_x_get_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 12:31:16 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/18 13:40:27 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char	*x_x_get_s(va_list *args, t_specifer *specifer)
{
	char	*s;
	char	*res;
	if (!specifer->modify)
		s = ft_itoa_base_un(va_arg(*args, unsigned int), 16);
	else if (specifer->modify == 'l')
		s = ft_itoa_base_lun(va_arg(*args, unsigned long int), 16);
	else if (specifer->modify == 'L')
		s = ft_itoa_base_lun(va_arg(*args, unsigned long long int), 16);
	else if (specifer->modify == 'h' || specifer->modify == 'H')
		s = ft_itoa_base_un(va_arg(*args, unsigned int), 16);
	else if (specifer->modify == 'j')
		s = ft_itoa_base_uintmax(va_arg(*args, uintmax_t), 16);
	else if (specifer->modify == 'z')
		s = ft_itoa_base_lun(va_arg(*args, size_t), 16);
	else
		s = NULL;
	res = ft_strnew(ft_strlen(s));
	res = ft_strcpy(res, s);
	return (res);
}

char	*o_o_get_s(va_list *args, t_specifer *specifer)
{
	char	*s;
	char	*res;

	if (!specifer->modify)
		s = ft_itoa_base_un(va_arg(*args, unsigned int), 8);
	else if (specifer->modify == 'l')
		s = ft_itoa_base_lun(va_arg(*args, unsigned long int), 8);
	else if (specifer->modify == 'L')
		s = ft_itoa_base_lun(va_arg(*args, unsigned long long int), 8);
	else if (specifer->modify == 'h' || specifer->modify == 'H')
		s = ft_itoa_base_un(va_arg(*args, unsigned int), 8);
	else if (specifer->modify == 'j')
		s = ft_itoa_base_uintmax(va_arg(*args, uintmax_t), 8);
	else if (specifer->modify == 'z')
		s = ft_itoa_base_lun(va_arg(*args, size_t), 8);
	else
		s = NULL;
	res = ft_strnew(ft_strlen(s));
	res = ft_strcpy(res, s);
	return (res);
}

char	*u_u_get_s(va_list *args, t_specifer *specifer)
{
	char	*s;
	char	*res;

	if (specifer->tr == 'U')
	{
		if (!specifer->modify)
			specifer->modify = 'l';
		else if (specifer->modify == 'l')
			specifer->modify = 'L';
		else if (specifer->modify == 'h' || specifer->modify == 'H')
			specifer->modify = 'L';
	}
	if (!specifer->modify)
		s = ft_itoa_base_un(va_arg(*args, unsigned int), 10);
	else if (specifer->modify == 'l')
		s = ft_itoa_base_lun(va_arg(*args, unsigned long int), 10);
	else if (specifer->modify == 'L')
		s = ft_itoa_base_lun(va_arg(*args, unsigned long long int), 10);
	else if (specifer->modify == 'h' || specifer->modify == 'H')
		s = ft_itoa_base_un(va_arg(*args, unsigned int), 10);
	else if (specifer->modify == 'j')
		s = ft_itoa_base_uintmax(va_arg(*args, uintmax_t), 10);
	else if (specifer->modify == 'z')
		s = ft_itoa_base_lun(va_arg(*args, size_t), 10);
	else
		s = NULL;
	res = ft_strnew(ft_strlen(s));
	res = ft_strcpy(res, s);
	return (res);
}

