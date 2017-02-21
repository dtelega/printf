/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:57:00 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/20 20:02:10 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char		*d_i_check_flag(char *s, t_specifer *specifer)
{
	int		i;

	if (specifer->flag_zero == '0' && specifer->flag_minus)
		specifer->flag_zero = '\0';
	if (specifer->flag_space == ' ' && specifer->flag_plus)
		specifer->flag_space = '\0';
	if (specifer->flag_zero == '0' && specifer->accur >= 0)
		specifer->flag_zero = '\0';
	if (specifer->flag_zero == '0' && specifer->accur == -1)
	{
		i = 0;
		while (s[i] == ' ')
			s[i++] = '0';
		if (i > 0 && (s[i] == '-' || s[i] == '+'))
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

void		d_i(t_specifer *specifer, va_list *args, t_format *formats,
				int count)
{
	char	*s;

	s = d_i_get_s(args, specifer, &count);
	if (!ft_strcmp(s, "0") && specifer->accur == 0 && (count = 0) == 0)
		s = "\0";
	if (specifer->accur > 0)
		while (specifer->accur-- > count)
			s = ft_strjoin("0", s);
	if (specifer->flag_plus == '+')
		s = ft_strjoin("+", s);
	else if (specifer->flag_plus == '-')
		s = ft_strjoin("-", s);
	if (!specifer->flag_plus && specifer->flag_space)
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
	put_len(s, formats, 0);
}

void		d_big(t_specifer *specifer, va_list *args, t_format *formats)
{
	char	*s;

	s = ft_itoa_l(va_arg(*args, long));
	if (!ft_strcmp(s, "0") && specifer->accur == 0)
		s = "\0";
	ft_putstr(s);
	formats->len += ft_strlen(s);
}
