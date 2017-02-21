/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 17:08:04 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/21 17:13:19 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int		ft_atoi_l(const char *str)
{
	long long int		nb;
	int					neg;
	int					i;

	i = 0;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
	|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + (str[i] - '0');
		i++;
	}
	if (neg == 1)
		return (-nb);
	else
		return (nb);
}
