/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:29:20 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/21 18:26:08 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

t_specifer		get_specifer(t_format *formats, int *i, int fl)
{
	char		cur;
	t_specifer	specifer;

	specifer = clean_spec(&specifer);
	while ((cur = formats->format[*i + (fl++)]) &&
	(its_tr(cur) || its_modify(cur) || (cur >= '0' && cur <= '9') ||
			cur == '.' || its_flag(cur, formats->format[*i + fl - 2])))
	{
		if (its_flag(cur, formats->format[*i + fl - 2]))
			get_flag(&specifer, cur);
		else if (its_modify(cur))
			get_modify(cur, &specifer, formats->format[*i + fl], &(*i));
		else if (cur == '.')
			get_accur(&(*formats), &(*i), &fl, &specifer);
		else if (its_tr(cur) && (specifer.tr = cur))
			return ((*i += fl - 1) ? specifer : specifer);
		else if (cur >= '0' && cur <= '9')
			specifer.weight = specifer.weight * 10 + cur - '0';
	}
	ft_without(&specifer, formats);
	*i += fl - 2;
	return (specifer);
}

void			print_shit(t_specifer *specifer, va_list *args,
							t_format *formats)
{
	char	*s;

	s = ft_strnew(2);
	if (specifer->tr == 'd' || specifer->tr == 'i')
		d_i(specifer, args, formats, 0);
	else if (specifer->tr == 'c' || specifer->tr == 'C')
	{
		s[0] = va_arg(*args, int);
		c_c(specifer, s, formats, 0);
	}
	else if (specifer->tr == 's' || specifer->tr == 'S')
		s_s(specifer, va_arg(*args, char *), formats);
	else if (specifer->tr == 'D')
		d_big(specifer, args, formats);
	else if (specifer->tr == '%')
		procent(specifer, formats);
	else if (specifer->tr == 'o' || specifer->tr == 'O')
		o_o(args, specifer, formats);
	else if (specifer->tr == 'x' || specifer->tr == 'X')
		x_x(args, specifer, formats, 0);
	else if (specifer->tr == 'p')
		p_tr(args, specifer, formats);
	if (specifer->tr == 'u' || specifer->tr == 'U')
		u_u(args, specifer, formats);
	free(s);
}

void			ft_convers_printf(t_format *formats, va_list *args)
{
	char		current;
	int			i;
	t_specifer	specifer;

	formats->len = 0;
	i = 0;
	while ((current = (formats->format)[i]))
	{
		if (current == '%')
		{
			i++;
			if (!formats->format[i])
				return ;
			specifer = get_specifer(formats, &i, 0);
			print_shit(&specifer, args, formats);
		}
		else
		{
			ft_putchar(current);
			formats->len++;
		}
		i++;
	}
}

int				ft_printf(const char *format, ...)
{
	va_list		args;
	t_format	formats;

	if (!format)
	{
		ft_putstr_fd("ft_printf: format must be valid\n", 2);
		return (0);
	}
	va_start(args, format);
	formats.format = (char *)format;
	ft_convers_printf(&formats, &args);
	va_end(args);
	return (formats.len);
}
