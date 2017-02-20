/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_without_tr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 18:41:02 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/20 19:15:17 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void	ft_without(t_specifer *specifer, t_format *t_format)
{
	char	*s;
	int		i;
	char	field;

	if (specifer->weight == 0)
		return ;
	s = ft_strnew(specifer->weight);
	field = ' ';
	if (specifer->flag_zero == '0')
		field = '0';
	i = 0;
	while (i != specifer->weight - 1)
		s[i++] = field;
	ft_putstr(s);
	t_format->len += ft_strlen(s);
	free(s);
}
