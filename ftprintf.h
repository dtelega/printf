/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:17:17 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/20 19:06:56 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H
# include <stdarg.h>
# include "libft.h"

# include <stdio.h>

typedef struct		s_specifer
{
	char		flag_minus;
	char		flag_plus;
	char		flag_space;
	char		flag_hesh;
	char		flag_zero;
	int			weight;
	int			accur;
	char		modify;
	char		tr;
}					t_specifer;

typedef struct		s_format
{
	char		*format;
	int			len;
	char		*specifer;

}					t_format;

typedef struct		s_dtoa
{
	char	*result;
	char	*temp;
	char	*fstr;
	size_t	ipart;
}					t_dtoa;

void				ft_without(t_specifer *specifer, t_format *t_format);
char				*rm_minus(char *s);
char				*ft_itoa_base_uintmax(uintmax_t value, int base);
char				*ft_itoa_base_lun(unsigned long int value, int base);
char				*u_u_get_s(va_list *args, t_specifer *specifer);
char				*o_o_get_s(va_list *args, t_specifer *specifer);
char				*x_x_get_s(va_list *args, t_specifer *specifer);
size_t				ft_llintlen(long long int a);
char				*ft_itoa_ll(long long int n);
char				*ft_itoa_sig(signed char n);
char				*d_i_get_s(va_list *args, t_specifer *specifer);
t_specifer			clean_spec(t_specifer *specifer);
void				d_big(t_specifer *specifer, va_list *args, t_format *t_format);
void				p_tr(va_list *args, t_specifer *specifer, t_format *t_format);
void				u_u(va_list *args, t_specifer *specifer, t_format *t_format);
void				o_o(va_list *args, t_specifer *specifer, t_format *t_format);
void				x_x(va_list *args, t_specifer *specifer, t_format *t_format);
void				s_s(t_specifer *specifer, char *s, t_format *t_format);
void				procent(t_specifer *specifer, t_format *format);
void				c_c(t_specifer *specifer, char *c, t_format *t_format);
void				d_i(t_specifer *specifer, va_list *args, t_format *t_format);
char				*ft_itoa_l(long int n);
long long int		ft_atoi_ll(const char *str);
long int			ft_atoi_l(const char *str);
char				*ft_more_memory(char *str, int size);
int					its_tr(char c);
void				get_accur(t_format *t_format, int *i, int *fl, t_specifer *specifer);
void				get_modify(char cur, t_specifer *specifer, char next, int *i);
int					its_modify(char cur);
void				get_flag(t_specifer *specifer, char cur);
int					its_flag(char cur, char prev);
char				*ft_tolowstr(char *s);
char				*ft_itoa_base(int value, int base);
char				*ft_itoa_base_un(unsigned int value, int base);
void				ft_putlongnbr(long int n);
size_t				ft_longintlen(long int a);
char				*ft_dtoa(double num, size_t n);
int					ft_printf(const char *format, ...);

#endif
