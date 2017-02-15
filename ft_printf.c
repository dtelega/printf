/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:29:20 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/15 20:02:23 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

t_specifer		get_specifer(t_format *t_format, int *i)
{
	char		cur;
	t_specifer	specifer;
	int			fl;

	fl = 0;
	while ((cur = t_format->format[*i + (fl++)]) && (its_tr(cur) || 
		   (its_modify(cur) || its_flag(cur, t_format->format[*i + fl - 2]) ||
			cur == '.' || (cur >= '0' && cur <= '9'))))
	{
		if (its_flag(cur, t_format->format[*i + fl - 2]))
			get_flag(&specifer, cur);
		else if (its_modify(cur))
			get_modify(cur, &specifer, t_format->format[*i + fl], &(*i));
		else if (cur == '.')
			get_accur(&(*t_format), &(*i), &fl, &specifer);
		else if (cur >= '0' && cur <= '9')
			specifer.weight = specifer.weight * 10 + cur - '0';
		else if (its_tr(cur))
		{
			specifer.tr = cur;
			break ;
		}
	}
	*i += fl - 1;
	return (specifer);
}

void	print_shit(t_specifer *specifer, va_list *args, t_format *t_format)
{
	char	*s;

	s = ft_strnew(2);
	if (specifer->tr == 'd' || specifer->tr == 'i')  // need MOD
		d_i(specifer, args, t_format);
	else if (specifer->tr == 'c' || specifer->tr == 'C')    // done
	{
		s[0] = va_arg(*args, int);
		c_C(specifer, s, t_format);
	}
	else if (specifer->tr == 's' || specifer->tr == 'S') // done
		s_S(specifer, va_arg(*args, char *), t_format);
	else if (specifer->tr == 'D')
		s = ft_itoa_l(va_arg(*args, long int));
	else if (specifer->tr == '%')            // done
		procent(specifer, t_format);
	else if (specifer->tr == 'f')
		s = ft_dtoa(va_arg(*args, double), 6);
	else if (specifer->tr == 'o' || specifer->tr == 'O') // done, need MOD
		o_O(ft_itoa_base(va_arg(*args, int), 8), specifer, t_format);
	else if (specifer->tr == 'x' || specifer->tr == 'X') // done, need MOD
		x_X(ft_itoa_base(va_arg(*args, int), 16), specifer, t_format);
	if (specifer->tr == 'u' || specifer->tr == 'U')
		u_U(ft_itoa(va_arg(*args, unsigned int)), specifer, t_format);
}

void	ft_convers_printf(t_format *t_format, va_list *args)
{
	char		current;
	int			i;
	t_specifer 	specifer;

	t_format->len = 0;
	i = 0;
	while ((current = (t_format->format)[i]))
	{
		if (current == '%')
		{
			i++;
			specifer = get_specifer(t_format, &i);
// ----------test----- 
/*printf("      SPECIFER:\n");
printf("        flag     :%c|\n", specifer.flag_minus);
printf("        flag     :%s|\n", specifer.flag_plus);
printf("        flag     :%c|\n", specifer.flag_space);
printf("        flag     :%c|\n", specifer.flag_hesh);
printf("        flag     :%c|\n", specifer.flag_zero);
printf("        weight   :%d|\n", specifer.weight);
printf("        accur    :%d|\n", specifer.accur);
printf("        modify   :%c|\n", specifer.modify);
printf("        tr       :%c|\n", specifer.tr);*/
// --------------------;
			print_shit(&specifer, args, t_format);
		}
		else
		{
			ft_putchar(current);
			t_format->len++;
		}
		i++;
	}
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	t_format	t_format;
	
	if (!format)
	{
		ft_putstr_fd("ft_printf: format must be valid\n", 2);
		return (0);
	}
	va_start(args, format);
	t_format.format = (char *)format;
	ft_convers_printf(&t_format, &args);
	va_end(args);
	return (t_format.len);
}
