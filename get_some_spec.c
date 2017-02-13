/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_some_spec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 11:41:22 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/12 16:11:20 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int		its_flag(char cur, char prev)
{
	if (cur == '-' || cur == '+' || cur == ' ' || cur == '#' ||
		(cur == '0' && (prev < '0' || prev > '9')))
		return (1);
	return (0);
}

void	get_modify(char cur, t_specifer *specifer, char next, int *i)
{
	if (cur == 'l' && next == 'l')
		specifer->modify = 'L';
	else if (cur == 'l' && next != 'l' && specifer->modify != 'L')
		specifer->modify = 'l';
	else if (cur == 'h' && next != 'h' && specifer->modify != 'L' &&
			 specifer->modify != 'l')
		specifer->modify = 'h';
	else if (cur == 'h' && next == 'h' && !specifer->modify)
	{
		(*i)++;
		specifer->modify = 'H';
	}
}

int		its_modify(char cur)
{
	if (cur == 'l' || cur == 'h')
		return (1);
	return (0);
}

void		get_accur(t_format *t_format, int *i, int *fl, t_specifer *specifer)
{
	int		res;
	char	cur;

	res = 0;
	while ((cur = t_format->format[*i + *fl]) >= '0' && cur <= '9')
	{
		res = res * 10 + cur - '0';
		(*fl)++;
	}
	specifer->accur = res;
}

int			its_tr(char c)
{
	if (c == 'd' || c == 'D' || c == 's' || c == 'S' || c == 'p' || c == 'o' ||
		c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'c' ||
		c == 'C' || c == '%' || c == 'i')
		return (1);
	return (0);
}
