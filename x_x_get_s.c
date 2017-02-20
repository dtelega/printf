/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_x_get_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 12:31:16 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/20 20:19:07 by dtelega          ###   ########.fr       */
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
	else if (specifer->modify == 'h')
		s = ft_itoa_base_un((unsigned short int)va_arg(*args, unsigned int), 16);
	else if (specifer->modify == 'H')
		s = ft_itoa_base_un((unsigned int)va_arg(*args, unsigned int), 16);
	else if (specifer->modify == 'j')
		s = ft_itoa_base_lun(va_arg(*args, unsigned long long), 16);
	else if (specifer->modify == 'z')
		s = ft_itoa_base_lun(va_arg(*args, unsigned long long), 16);
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
		s = ft_itoa_base_lun(va_arg(*args, unsigned long long), 8);
	else if (specifer->modify == 'l')
		s = ft_itoa_base_lun(va_arg(*args, unsigned long long), 8);
	else if (specifer->modify == 'L')
		s = ft_itoa_base_lun(va_arg(*args, unsigned long long), 8);
	else if (specifer->modify == 'h')
		s = ft_itoa_base_un((unsigned short int)
							va_arg(*args, unsigned long long), 8);
	else if (specifer->modify == 'H')
		s = ft_itoa_base_lun((unsigned short)
							va_arg(*args, unsigned long long), 8);
	else if (specifer->modify == 'j')
		s = ft_itoa_base_lun(va_arg(*args, unsigned long long), 8);
	else if (specifer->modify == 'z')
		s = ft_itoa_base_lun(va_arg(*args, unsigned long long), 8);
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

	if (!specifer->modify && specifer->tr == 'u')
		s = ft_itoa_base_un(va_arg(*args, unsigned long), 10);
	else if (specifer->modify == 'l' || specifer->tr == 'U')
		s = ft_itoa_base_lun(va_arg(*args, unsigned long long), 10);
	else if (specifer->modify == 'L')
		s = ft_itoa_base_lun(va_arg(*args, unsigned long long), 10);
	else if (specifer->modify == 'h')
		s = ft_itoa_base_un((unsigned short int)
							va_arg(*args, unsigned int), 10);
	else if (specifer->modify == 'H')
		s = ft_itoa_base_un((unsigned char)
							va_arg(*args, unsigned int), 10);
	else if (specifer->modify == 'j')
		s = ft_itoa_base_lun(va_arg(*args, unsigned long long), 10);
	else if (specifer->modify == 'z')
		s = ft_itoa_base_lun(va_arg(*args, size_t), 10);
	else
		s = NULL;
	res = ft_strnew(ft_strlen(s));
	res = ft_strcpy(res, s);
	return (res);
}

