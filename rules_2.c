/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:21:01 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/19 18:17:13 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void	c_c(t_specifer *specifer, char *c, t_format *format, int i)
{
	char	*res;

	res = ft_strnew(1);
	if (c[0] != 0)
		res = ft_strcpy(res, c);
	else
		format->len++;
	if (specifer->weight > 0)
		while (i++ + 1 != specifer->weight)
		{
			if (!specifer->flag_minus)
			{
				if (specifer->flag_zero == '0')
					res = ft_strjoin("0", res);
				else
					res = ft_strjoin(" ", res);
			}
			else
				res = ft_strjoin(res, " ");
		}
	ft_putstr(res);
	if (c[0] == 0)
		write(1, "\0", 1);
	format->len += ft_strlen(res);
	free(res);
}

int		check_s_null(char *s, t_specifer *specifer, t_format *format)
{
	if (s == NULL && specifer->accur != 0)
	{
		ft_putstr("(null)");
		format->len += 6;
		return (1);
	}
	return (0);
}

void	s_s(t_specifer *specifer, char *s, t_format *format)
{
	int		count;
	char	*res;

	if (check_s_null(s, specifer, format) == 1)
		return ;
	else if (s == NULL && specifer->accur == 0)
		s = "\0";
	res = ft_strnew(ft_strlen(s));
	res = ft_strcpy(res, s);
	if (specifer->accur < (int)ft_strlen(res) && specifer->accur >= 0)
		res[specifer->accur] = '\0';
	count = specifer->weight - (int)ft_strlen(res);
	while (count-- > 0)
	{
		if (specifer->flag_minus)
			res = ft_strjoin(res, " ");
		else
		{
			if (!specifer->flag_zero)
				res = ft_strjoin(" ", res);
			else
				res = ft_strjoin("0", res);
		}
	}
	put_len(res, format, 1);
}

void	procent(t_specifer *specifer, t_format *format)
{
	char	*res;
	char	field;
	int		i;

	res = ft_strnew(specifer->weight > 1 ? specifer->weight : 1);
	if (specifer->flag_zero && !specifer->flag_minus)
		field = '0';
	else
		field = ' ';
	i = 0;
	while (i < specifer->weight - 1)
		res[i++] = field;
	if (specifer->flag_minus)
		res = ft_strjoin("%", res);
	else
		res = ft_strjoin(res, "%");
	ft_putstr(res);
	format->len += ft_strlen(res);
	free(res);
}
