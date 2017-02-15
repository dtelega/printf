/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:57:00 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/15 18:03:42 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int		max(int a, int b, int c)
{
	return ((a > b)? ((a > c)? a : c) : ((b > c)? b : c));
}

char		*d_i_check_flag(char *s, t_specifer *specifer)
{
	int		i;

	if (specifer->flag_zero && specifer->flag_minus)
		specifer->flag_zero = '\0';
	if (specifer->flag_space && specifer->flag_plus)
		specifer->flag_space = '\0';
	if (specifer->flag_zero)
	{
		i = 0;
		while (s[i] == ' ')
			s[i++] = '0';
		if (s[i] == '+' || s[i] == '-')
		{
			s[0] = s[i];
			s[i] = '0';
		}
	}
	if (specifer->flag_space)
		if (s[0] == '0')
			s[0] = ' ';
	return (s);
}

void	d_i(t_specifer *specifer, va_list *args, t_format *t_format) // "0", " ", mod - nety
{
	char	*s;
	int		count;

	s = ft_itoa(va_arg(*args, int));
	if (s[0] == '-' && (specifer->flag_plus = "-"))
		s = ft_itoa(-ft_atoi(s));
	count = (int)ft_strlen(s);
	while (specifer->accur-- > count)
		s = ft_strjoin("0", s);
	if (specifer->flag_plus)
		s = ft_strjoin(specifer->flag_plus, s);
	else if (!specifer->flag_plus && specifer->flag_space)
		s = ft_strjoin(" ", s);
	count = ft_strlen(s);
	while (specifer->weight-- > count)
	{
		if (specifer->flag_minus)
			s = ft_strjoin(s, " ");
		else
			s = ft_strjoin(" ", s);
	}
	s = d_i_check_flag(s, specifer);
	ft_putstr(s);
	t_format->len += ft_strlen(s);
}
