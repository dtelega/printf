/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 16:12:22 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/17 17:43:51 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void	get_flag(t_specifer *specifer, char cur)
{
	if (cur == '-')
		specifer->flag_minus = cur;
	else if (cur == '+')
		specifer->flag_plus = '+';
	else if (cur == ' ')
		specifer->flag_space = cur;
	else if (cur == '#')
		specifer->flag_hesh = cur;
	else if (cur == '0')
		specifer->flag_zero = cur;
	else
		return ;
}
