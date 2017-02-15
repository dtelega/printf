/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:21:01 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/15 18:10:17 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void	c_C(t_specifer *specifer, char *c, t_format *t_format)
{
	char	*res;
	int		i;

	res = ft_strnew(specifer->weight > 1 ? specifer->weight : 1);
	i = 0;
	if (specifer->weight > 0)
		while (i + 1 != specifer->weight)
			res[i++] = ' ';
	if (specifer->flag_minus)
		res = ft_strjoin(c, res);
	else
		res = ft_strjoin(res, c);
	free(specifer);
	ft_putstr(res);
	t_format->len += ft_strlen(res);
}

void	s_S(t_specifer *specifer, char *s, t_format *t_format)
{
	char	*res;
	int		count;

	res = ft_strnew(specifer->weight > ft_strlen(s) ? specifer->weight :
					ft_strlen(s));
	res = ft_strncpy(res, s, specifer->accur < (int)ft_strlen(s) ?
						 specifer->accur : (int)ft_strlen(s));
	count = specifer->weight - (int)ft_strlen(res);
	while (count-- > 0)
	{
		if (specifer->flag_minus)
			res = ft_strjoin(res, " ");
		else
			res = ft_strjoin(" ", res);
	}
	ft_putstr(res);
	t_format->len += ft_strlen(res);
}

void	procent(t_specifer *specifer, t_format *t_format)
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
	t_format->len += ft_strlen(res);
}
