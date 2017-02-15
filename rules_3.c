/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:08:56 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/15 20:14:01 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void	o_O(char *s, t_specifer *specifer, t_format *t_format)
{
	int		count;

	count = (int)ft_strlen(s);
	while (specifer->accur > count++)
		s = ft_strjoin("0", s);
	count = (int)ft_strlen(s);
	while (specifer->weight > count++)
	{
		if (specifer->flag_minus)
			s = ft_strjoin(s, " ");
		else
			s = ft_strjoin(" ", s);
	}
	ft_putstr(s);
	t_format->len += ft_strlen(s);
}

void	x_X(char *s, t_specifer *specifer, t_format *t_format)
{
	int		count;

	count = (int)ft_strlen(s);
	while (specifer->accur > count++)
		s = ft_strjoin("0", s);
	if (specifer->flag_hesh)
		s = ft_strjoin("0X", s);
	count = (int)ft_strlen(s);
	while (specifer->weight > count++)
	{
		if (specifer->flag_minus)
			s = ft_strjoin(s, " ");
		else
			s = ft_strjoin(" ", s);
	}
	if (specifer->tr == 'x')
		s = ft_tolowstr(s);
	ft_putstr(s);
	t_format->len += ft_strlen(s);
}

void	u_U(char *s, t_specifer *specifer, t_format *t_format)
{
	int		count;


	if (s[0] == '-')
	{
		s = ft_itoa_l(4294967296 + ft_atoi(s));
	}
	count = (int)ft_strlen(s);
	while (specifer->accur > count++)
		s = ft_strjoin("0", s);
	count = (int)ft_strlen(s);
	while (specifer->weight > count++)
	{
		if (specifer->flag_minus)
			s = ft_strjoin(s, " ");
		else
			s = ft_strjoin(" ", s);
	}
	ft_putstr(s);
	t_format->len += ft_strlen(s);
}
