/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:08:56 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/18 13:51:12 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void	o_o(va_list *args, t_specifer *specifer, t_format *t_format)
{
	int		count;
	char	*s;

	s = o_o_get_s(args, specifer);
	if (!ft_strcmp(s, "0") && specifer->accur == 0)
		s = "\0";
	count = (int)ft_strlen(s);
	if (specifer->flag_zero && specifer->accur == -1 && !specifer->flag_minus)
		specifer->accur = specifer->weight;
	while (specifer->accur > count++)
		s = ft_strjoin("0", s);
	if (specifer->flag_hesh == '#')
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

void	x_x(va_list *args, t_specifer *specifer, t_format *t_format)
{
	int		count;
	char	*s;

	s = x_x_get_s(args, specifer);
	if (!ft_strcmp(s, "0"))
		specifer->flag_hesh = '\0';
	if (!ft_strcmp(s, "0") && specifer->accur == 0)
		s = "\0";
	if (specifer->accur == -1 && specifer->flag_zero && !specifer->flag_minus)
		specifer->accur = specifer->weight - (!specifer->flag_hesh ? 0 : 2);
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

void	u_u(va_list *args, t_specifer *specifer, t_format *t_format)
{
	int		count;
	char	*s;

	s = u_u_get_s(args, specifer);
	count = (int)ft_strlen(s);
	if (specifer->flag_zero && specifer->accur == -1 && !specifer->flag_minus)
		specifer->accur = specifer->weight;
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
