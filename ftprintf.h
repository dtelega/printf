/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:17:17 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/13 15:43:50 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
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

char		*ft_itoa_long(long int n);
char		*ft_more_memory(char *str, int size);
int			its_tr(char c);
void		get_accur(t_format *t_format, int *i, int *fl, t_specifer *specifer);
void		get_modify(char cur, t_specifer *specifer, char next, int *i);
int			its_modify(char cur);
void		get_flag(t_specifer *specifer, char cur);
int			its_flag(char cur, char prev);
char		*ft_tolowstr(char *s);
char		*ft_itoa_base(int value, int base);
void		ft_putlongnbr(long int n);
size_t		ft_longintlen(long int a);
char		*ft_dtoa(double num, size_t n);
int			ft_printf(const char *format, ...);

#endif
