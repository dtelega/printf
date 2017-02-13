/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 14:25:15 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/12 17:31:23 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char	*ft_more_memory(char *str, int size)
{
	char	*new;

	if (size <= 0)
		return (str);
	new = ft_strnew(ft_strlen(str) + size);
	new = ft_strcpy(new, str);
	free(str);
	return (new);
}
