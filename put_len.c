/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:02:07 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/21 18:03:36 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void	put_len(char *res, t_format *format, int can_free)
{
	ft_putstr(res);
	format->len += ft_strlen(res);
	if (can_free == 1)
		free(res);
}
